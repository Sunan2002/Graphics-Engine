/*========== my_main.c ==========

  This is the only file you need to modify in order
  to get a working mdl project (for now).

  my_main.c will serve as the interpreter for mdl.
  When an mdl script goes through a lexer and parser,
  the resulting operations will be in the array op[].

  Your job is to go through each entry in op and perform
  the required action from the list below:

  push: push a new origin matrix onto the origin stack

  pop: remove the top matrix on the origin stack

  move/scale/rotate: create a transformation matrix
                     based on the provided values, then
                     multiply the current top of the
                     origins stack by it.

  box/sphere/torus: create a solid object based on the
                    provided values. Store that in a
                    temporary matrix, multiply it by the
                    current top of the origins stack, then
                    call draw_polygons.

  line: create a line based on the provided values. Store
        that in a temporary matrix, multiply it by the
        current top of the origins stack, then call draw_lines.

  save: call save_extension with the provided filename

  display: view the screen
  =========================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "parser.h"
#include "symtab.h"
#include "y.tab.h"

#include "matrix.h"
#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "stack.h"
#include "gmath.h"

/*======== void first_pass() ==========
  Inputs:
  Returns:

  Checks the op array for any animation commands
  (frames, basename, vary)

  Should set num_frames and basename if the frames
  or basename commands are present

  If vary is found, but frames is not, the entire
  program should exit.

  If frames is found, but basename is not, set name
  to some default value, and print out a message
  with the name being used.
  ====================*/
void first_pass() {
  //These variables are defined at the bottom of symtab.h
  extern int num_frames;
  extern char name[128];

  num_frames = -1;
  int exist = 0;
  for (int ctr = 0; ctr < lastop; ctr++) {
      switch (op[ctr].opcode) {
          case FRAMES:
            num_frames = op[ctr].op.frames.num_frames;
            break;
          case BASENAME:
            strcpy(name, op[ctr].op.basename.p->name);
            exist = 1;
            break;
          case VARY:
            if (num_frames == -1) {
                printf("No Frames");
                exit(0);
            }
            break;
      }
  }
  if (num_frames != -1 && !exist) {
      strcpy(name, "Example");
  }
  return;
}

/*======== struct vary_node ** second_pass() ==========
  Inputs:
  Returns: An array of vary_node linked lists

  In order to set the knobs for animation, we need to keep
  a seaprate value for each knob for each frame. We can do
  this by using an array of linked lists. Each array index
  will correspond to a frame (eg. knobs[0] would be the first
  frame, knobs[2] would be the 3rd frame and so on).

  Each index should contain a linked list of vary_nodes, each
  node contains a knob name, a value, and a pointer to the
  next node.

  Go through the opcode array, and when you find vary, go
  from knobs[0] to knobs[frames-1] and add (or modify) the
  vary_node corresponding to the given knob with the
  appropirate value.
  ====================*/
struct vary_node ** second_pass() {
  struct vary_node *curr = NULL;
  struct vary_node **knobs;
  knobs = (struct vary_node **)calloc(num_frames, sizeof(struct vary_node *));
  for(int fr = 0; fr < num_frames; fr++) {
      struct vary_node* head = NULL;

      for (int ctr = 0; ctr < lastop; ctr++) {
          switch (op[ctr].opcode) {
              case VARY:
              if (fr >= op[ctr].op.vary.start_frame && fr <= op[ctr].op.vary.end_frame) {
                  float setframe = fr - op[ctr].op.vary.start_frame;
                  float setval = setframe / (op[ctr].op.vary.end_frame - op[ctr].op.vary.start_val) * (op[ctr].op.vary.end_val - op[ctr].op.vary.start_val);

                  struct vary_node *node = (struct vary_node*) malloc(sizeof(struct vary_node));
                  strcpy(node->name, op[ctr].op.vary.p->name);
                  node->value = op[ctr].op.vary.start_val + setval;
                  node->next = head;
                  head = node;
              }
              break;
          }
      }
      knobs[fr] = head;
  }
  return knobs;
}

void my_main() {

  struct vary_node ** knobs;
  struct vary_node * nv;
  first_pass();
  knobs = second_pass();
  char frame_name[128];
  int f;

  int i;
  struct matrix *tmp;
  struct stack *systems;
  screen t;
  zbuffer zb;
  double step_3d = 100;
  double theta, xval, yval, zval, knob_val;

  int shading = PHONG; 

  //Lighting values here for easy access
  color ambient;
  ambient.red = 50;
  ambient.green = 50;
  ambient.blue = 50;

  double light[2][3];
  light[LOCATION][0] = 0.5;
  light[LOCATION][1] = 0.75;
  light[LOCATION][2] = 1;

  light[COLOR][RED] = 255;
  light[COLOR][GREEN] = 255;
  light[COLOR][BLUE] = 255;

  double view[3];
  view[0] = 0;
  view[1] = 0;
  view[2] = 1;

  //default reflective constants if none are set in script file
  struct constants white;
  white.r[AMBIENT_R] = 0.1;
  white.g[AMBIENT_R] = 0.1;
  white.b[AMBIENT_R] = 0.1;

  white.r[DIFFUSE_R] = 0.5;
  white.g[DIFFUSE_R] = 0.5;
  white.b[DIFFUSE_R] = 0.5;

  white.r[SPECULAR_R] = 0.5;
  white.g[SPECULAR_R] = 0.5;
  white.b[SPECULAR_R] = 0.5;

  //constants are a pointer in symtab, using one here for consistency
  struct constants *reflect;
  reflect = &white;

  color g;
  g.red = 255;
  g.green = 255;
  g.blue = 255;

  for (f=0; f < num_frames; f++) {

    systems = new_stack();
    tmp = new_matrix(4, 1000);
    clear_screen( t );
    clear_zbuffer(zb);

    //if there are multiple frames, set the knobs
    if ( num_frames > 1 ) {
      nv = knobs[f];

      while ( nv ) {
        //printf("\tknob: %s value:%lf\n", nv->name, nv->value);
        set_value( lookup_symbol( nv->name ), nv->value );
        nv = nv-> next;
      } //end while knobs
    }//end if multiple frames

    for (i=0;i<lastop;i++) {

      //printf("%d: ",i);
      switch (op[i].opcode)
        {
        case SPHERE:
          /* printf("Sphere: %6.2f %6.2f %6.2f r=%6.2f", */
          /*        op[i].op.sphere.d[0],op[i].op.sphere.d[1], */
          /*        op[i].op.sphere.d[2], */
          /*        op[i].op.sphere.r); */
          if (op[i].op.sphere.constants != NULL) {
            //printf("\tconstants: %s",op[i].op.sphere.constants->name);
            reflect = lookup_symbol(op[i].op.sphere.constants->name)->s.c;
          }
          if (op[i].op.sphere.cs != NULL) {
            //printf("\tcs: %s",op[i].op.sphere.cs->name);
          }
          add_sphere(tmp, op[i].op.sphere.d[0],
                     op[i].op.sphere.d[1],
                     op[i].op.sphere.d[2],
                     op[i].op.sphere.r, step_3d);
          matrix_mult( peek(systems), tmp );
          draw_polygons(tmp, t, zb, view, ambient,
                        reflect, shading);
          tmp->lastcol = 0;
          reflect = &white;
          break;

        case TORUS:
          /* printf("Torus: %6.2f %6.2f %6.2f r0=%6.2f r1=%6.2f", */
          /*        op[i].op.torus.d[0],op[i].op.torus.d[1], */
          /*        op[i].op.torus.d[2], */
          /*        op[i].op.torus.r0,op[i].op.torus.r1); */
          if (op[i].op.torus.constants != NULL) {
            //printf("\tconstants: %s",op[i].op.torus.constants->name);
            reflect = lookup_symbol(op[i].op.sphere.constants->name)->s.c;
          }
          if (op[i].op.torus.cs != NULL) {
            //printf("\tcs: %s",op[i].op.torus.cs->name);
          }
          add_torus(tmp,
                    op[i].op.torus.d[0],
                    op[i].op.torus.d[1],
                    op[i].op.torus.d[2],
                    op[i].op.torus.r0,op[i].op.torus.r1, step_3d);
          matrix_mult( peek(systems), tmp );
          draw_polygons(tmp, t, zb, view, ambient,
                        reflect, shading);
          tmp->lastcol = 0;
          reflect = &white;
          break;

        case BOX:
          /* printf("Box: d0: %6.2f %6.2f %6.2f d1: %6.2f %6.2f %6.2f", */
          /*        op[i].op.box.d0[0],op[i].op.box.d0[1], */
          /*        op[i].op.box.d0[2], */
          /*        op[i].op.box.d1[0],op[i].op.box.d1[1], */
          /*        op[i].op.box.d1[2]); */
          if (op[i].op.box.constants != NULL) {
            //printf("\tconstants: %s",op[i].op.box.constants->name);
            reflect = lookup_symbol(op[i].op.sphere.constants->name)->s.c;
          }
          if (op[i].op.box.cs != NULL) {
            //printf("\tcs: %s",op[i].op.box.cs->name);
          }
          add_box(tmp,
                  op[i].op.box.d0[0],op[i].op.box.d0[1],
                  op[i].op.box.d0[2],
                  op[i].op.box.d1[0],op[i].op.box.d1[1],
                  op[i].op.box.d1[2]);
          matrix_mult( peek(systems), tmp );
          draw_polygons(tmp, t, zb, view, ambient,
                        reflect, shading);
          tmp->lastcol = 0;
          reflect = &white;
          break;

        case MESH:
          if(op[i].op.mesh.constants != NULL){
            reflect = lookup_symbol(op[i].op.mesh.constants->name)->s.c;
          }
          if(op[i].op.mesh.cs != NULL){
            matrix_mult(op[i].op.mesh.cs->s.m, tmp);
          } 
          else {
            matrix_mult(peek(systems),tmp);
          }

        case LINE:
          /* printf("Line: from: %6.2f %6.2f %6.2f to: %6.2f %6.2f %6.2f", */
          /*        op[i].op.line.p0[0],op[i].op.line.p0[1], */
          /*        op[i].op.line.p0[2], */
          /*        op[i].op.line.p1[0],op[i].op.line.p1[1], */
          /*        op[i].op.line.p1[2]); */
          if (op[i].op.line.constants != NULL) {
            //printf("\n\tConstants: %s",op[i].op.line.constants->name);
          }
          if (op[i].op.line.cs0 != NULL) {
            //printf("\n\tCS0: %s",op[i].op.line.cs0->name);
          }
          if (op[i].op.line.cs1 != NULL) {
            //printf("\n\tCS1: %s",op[i].op.line.cs1->name);
          }
          add_edge(tmp,
                   op[i].op.line.p0[0],op[i].op.line.p0[1],
                   op[i].op.line.p0[2],
                   op[i].op.line.p1[0],op[i].op.line.p1[1],
                   op[i].op.line.p1[2]);
          matrix_mult( peek(systems), tmp );
          draw_lines(tmp, t, zb, g);
          tmp->lastcol = 0;
          break;

        case MOVE:
          xval = op[i].op.move.d[0];
          yval = op[i].op.move.d[1];
          zval = op[i].op.move.d[2];
          /* printf("Move: %6.2f %6.2f %6.2f", */
          /*        xval, yval, zval); */
          if (op[i].op.move.p != NULL) {
            //printf("\tknob: %s",op[i].op.move.p->name);
            knob_val = lookup_symbol(op[i].op.move.p->name)->s.value;
            xval*= knob_val;
            yval*= knob_val;
            zval*= knob_val;
          }
          tmp = make_translate( xval, yval, zval );
          matrix_mult(peek(systems), tmp);
          copy_matrix(tmp, peek(systems));
          tmp->lastcol = 0;
          break;

        case SCALE:
          xval = op[i].op.scale.d[0];
          yval = op[i].op.scale.d[1];
          zval = op[i].op.scale.d[2];
          /* printf("Scale: %6.2f %6.2f %6.2f", */
          /*        xval, yval, zval); */
          if (op[i].op.scale.p != NULL) {
            //printf("\tknob: %s",op[i].op.scale.p->name);
            knob_val = lookup_symbol(op[i].op.scale.p->name)->s.value;
            xval*= knob_val;
            yval*= knob_val;
            zval*= knob_val;
          }
          tmp = make_scale( xval, yval, zval );
          matrix_mult(peek(systems), tmp);
          copy_matrix(tmp, peek(systems));
          tmp->lastcol = 0;
          break;

        case ROTATE:
          /* printf("Rotate: axis: %6.2f degrees: %6.2f", */
          /*        op[i].op.rotate.axis, */
          /*        op[i].op.rotate.degrees); */
          theta =  op[i].op.rotate.degrees * (M_PI / 180);
          if (op[i].op.rotate.p != NULL) {
            //printf("\tknob: %s",op[i].op.rotate.p->name);
            knob_val = lookup_symbol(op[i].op.rotate.p->name)->s.value;
            theta*= knob_val;
          }

          if (op[i].op.rotate.axis == 0 )
            tmp = make_rotX( theta );
          else if (op[i].op.rotate.axis == 1 )
            tmp = make_rotY( theta );
          else
            tmp = make_rotZ( theta );

          matrix_mult(peek(systems), tmp);
          copy_matrix(tmp, peek(systems));
          tmp->lastcol = 0;
          break;

         case SHADING:
          if(!strcmp(op[i].op.shading.p->name,"standard")) shading = STANDARD;
          if(!strcmp(op[i].op.shading.p->name,"gouraud")) shading = GOURAUD;
          if(!strcmp(op[i].op.shading.p->name,"phong")) shading = PHONG;
          break;

        case PUSH:
          //printf("Push");
          push(systems);
          break;

        case POP:
          //printf("Pop");
          pop(systems);
          break;

        case SAVE:
          printf("Save: %s\n",op[i].op.save.p->name);
          save_extension(t, op[i].op.save.p->name);
          break;

        case DISPLAY:
          //printf("Display");
          display(t);
          break;
        }
      //printf("\n");
    } //end of the operation loop

    free_stack( systems );
    free_matrix( tmp );

    //saving the animation
    if (num_frames > 1) {
      sprintf(frame_name, "anim/%s%03d.png", name, f);
      save_extension( t, frame_name );
    } //end frame saving
  }//end frame loop

  //generate the gif
  if (num_frames > 1)
    make_animation( name );
}

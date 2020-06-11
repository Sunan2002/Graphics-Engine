# final_graphics

# Work 12: The End

## Proposal

### Sunan Tajwar, Period 10

### Features

## Implemented MDL Features:
- Implement the `mesh` command (compatible with .obj files)
- Save_Coordinate_System
- Added Cylinders
- Added Cones

## MDL Features I tried to implement but ultimately failed:
- Implement Gouraud and Phong shading using `shading` command

## Testing Files:
-final.mdl (Gallery Image)
-mesh_testing.mdl (Mesh with .obj files)
-shape_test.mdl (Cylinders and Cones)
-saveco_test.mdl (Save Coordinate System)


----------------------------------------------------------------------------------------------------------------------------
GitHub link: <https://github.com/mks66/final.git>

For the final project, you are to add any features you’d like to your current graphics engine. Below are some good places to start (you may work on other features if you prefer, just talk to me about it first

- **Existing, MDL Commands/Features:**
  - light
    - Add a light to the symbol table
    - When calculating diffuse and specular: loop through all the lights.
  - mesh
    - Use an external .obj file for polygons
    - Read up on the obj format [here](https://en.wikipedia.org/wiki/Wavefront_.obj_file).
    - Find example files [here](https://people.sc.fsu.edu/~jburkardt/data/obj/obj.html).
    - Make sure you deal with .obj files that list quadrilateral faces instead of triangles in some way.
  - set
    - Assign a value to a knob
  - saveknobs
    - Save current knob values to a list
  - tween
    - Produce an animation by going between two knob lists
  - shading
    - Use different shading techniques / calculating I more or less frequently.
    - A hash table structure can be very helpful for dealing with vertex normals. If you are woking in c, check out [uthash](https://troydhanson.github.io/uthash/).
  - save_coordinate_system
    - Save a copy of the top of the stack to the symbol table
    - use this coordinate system when drawing shapes (extra argument required)
- **Additions to MDL that require changes to the language:**
  - New primitive shapes
  - Change the behavior of vary
    - add a parameter to change how it calculates the change over time. e.g. Linear, Exponential, Logarithmic, Arbitrary equation, etc.
  - Anti-aliasing / Super-sampling
    - Reduce pixelated edges by calculating a higher resolution version of the image then reducing it to the intended size
  - Texture mapping
  - Using vary to move lights.

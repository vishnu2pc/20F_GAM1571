#include "GamePCH.h"
#include "Constants.h"
 const float VERTEX_MM_DARK_BLUE[108] =
{
    //Body Vertices

    -0.5f, -0.5f,       
    -0.1f, -0.5f,
    -0.3f, -0.3f,

    0.5f,  -0.5f,
    0.1f,  -0.5f,
    0.3f,  -0.3f,

    0.2f,  -0.2f,
    0.0f,  -0.3f,
    0.0f,  -0.1f,

    -0.2f,  -0.2f,
    0.0f,  -0.3f,
    0.0f,  -0.1f,

    -0.2f, -0.2f,
    -0.2f, -0.1f,
    0.0f,  -0.1f,

    0.2f,  -0.2f,
    0.2f,  -0.1f,
    0.0f,  -0.1f,

    -0.3f,  0.2f,
    -0.2f, -0.1f,
    -0.3f, -0.2f,

    0.3f,   0.2f,
    0.2f,  -0.1f,
    0.3f,  -0.2f,

    -0.3f, -0.2f,
    -0.3f,  0.2f,
    -0.5f, -0.1f,

    0.3f,  -0.2f,
    0.3f,   0.2f,
    0.5f,  -0.1f,

    // Head Vertices

    -0.0f, -0.0f,
    -0.3f, 0.2f,
    -0.3f, 0.3f,

     0.0f, -0.0f,
     0.3f, 0.2f,
     0.3f, 0.3f,

    -0.3f, 0.3f,
    -0.3f, 0.4f,
    -0.2f, 0.4f,

     0.3f, 0.3f,
     0.3f, 0.4f,
     0.2f, 0.4f,

    -0.3f, 0.4f,
    -0.0f, 0.4f,
    -0.0f, 0.6f,

     0.3f, 0.4f,
     0.0f, 0.4f,
     0.0f, 0.6f,

    -0.3f, 0.4f,
    -0.0f, 0.6f,
    -0.1f, 0.6f,

     0.3f, 0.4f,
     0.0f, 0.6f,
     0.1f, 0.6f,
};

 const GLenum VERTEX_MM_DARK_BLUE_MESH_TYPE = GL_TRIANGLES;
 const int VERTEX_MM_DARK_BLUE_NUM_VERTICES = sizeof(VERTEX_MM_DARK_BLUE) / (sizeof(float) * 2);
 
 const float VERTEX_MM_BLUE[84] =
{
    -0.3f, -0.3f,
    -0.2f, -0.2f,
    -0.1f, -0.5f,

    0.3f, -0.3f,
    0.2f, -0.2f,
    0.1f, -0.5f,

    -0.2f, -0.2f,
    -0.1f, -0.5f,
    0.0f, -0.3f,

    0.2f, -0.2f,
    0.1f, -0.5f,
    0.0f, -0.3f,

    -0.2f, -0.1f,
     0.0f, -0.1f,
     0.0f,  0.0f,

     0.2f, -0.1f,
     0.0f, -0.1f,
     0.0f,  0.0f,

     0.0f,  0.0f,
    -0.2f, -0.1f,
    -0.3f,  0.2f,

     0.0f,  0.0f,
     0.2f, -0.1f,
     0.3f,  0.2f,

    // Head Vertices

    -0.3f, 0.3f,
    -0.2f, 0.3f,
    -0.2f, 0.2f,

     0.3f, 0.3f,
     0.2f, 0.3f,
     0.2f, 0.2f,

    -0.3f, 0.3f,
    -0.2f, 0.3f,
    -0.2f, 0.4f,

     0.3f, 0.3f,
     0.2f, 0.3f,
     0.2f, 0.4f,

     0.05f, 0.4f,
    -0.05f, 0.4f,
     0.05f, 0.6f,

    -0.05f, 0.4f,
     0.05f, 0.6f,
    -0.05f, 0.6f
};

 const GLenum VERTEX_MM_BLUE_MESH_TYPE = GL_TRIANGLES;
 const int VERTEX_MM_BLUE_NUM_VERTICES = sizeof(VERTEX_MM_BLUE) / (sizeof(float) * 2);


const float VERTEX_MM_SKIN[36] =
{
     0.0f,  0.0f,
    -0.2f, 0.2f,
    -0.2f, 0.3f,

     0.0f,  0.0f,
     0.2f, 0.2f,
     0.2f, 0.3f,

    -0.2f, 0.3f,
    -0.2f, 0.4f,
     0.0f, 0.4f,

     0.2f, 0.3f,
     0.2f, 0.4f,
     0.0f, 0.4f,

    -0.2f, 0.3f,
     0.0f, 0.4f,
     0.0f,  0.0f,

     0.2f, 0.3f,
     0.0f, 0.4f,
     0.0f,  0.0f,
};

 const GLenum VERTEX_MM_SKIN_MESH_TYPE = GL_TRIANGLES;
 const int VERTEX_MM_SKIN_NUM_VERTICES = sizeof(VERTEX_MM_SKIN) / (sizeof(float) * 2);

 const float VERTEX_MM_FACE[72] =
{
    -0.1f, 0.3f,
    -0.1f, 0.25f,
    -0.05f, 0.3f,

      0.1f, 0.3f,
     0.1f, 0.25f,
     0.05f, 0.3f,

    -0.1f, 0.25f,
    -0.05f, 0.3f,
    -0.05f, 0.25f,

     0.1f, 0.25f,
     0.05f, 0.3f,
     0.05f, 0.25f,

    -0.05f, 0.10f,
     0.0f, 0.1f,
    -0.05f, 0.15f,

     0.05f, 0.1f,
     0.0f, 0.1f,
     0.05f, 0.15f,

     0.0f, 0.1f,
    -0.05f, 0.15f,
    -0.0f, 0.15f,

     0.0f , 0.1f,
     0.05f, 0.15f,
     0.0f , 0.15f
};

 const GLenum VERTEX_MM_FACE_MESH_TYPE = GL_TRIANGLES;
 const int VERTEX_MM_FACE_NUM_VERTICES = sizeof(VERTEX_MM_FACE) / (sizeof(float) * 2);


 const float VERTEX_DOG_FRONT_LEGS_RIGHT[22] =
{
    //Right Leg

    -0.12f, -0.4f,
    -0.2f, -0.4f,
    -0.16f, -0.36f,
    -0.16f, -0.24f,
    -0.26f, -0.16f,
    -0.26f, -0.0f,
    -0.2f,  0.1f,
    -0.2f, -0.0f,
    -0.2f, -0.14f,
    -0.08f, -0.2f,
    -0.10f, -0.36f

};

 const GLenum VERTEX_DOG_FRONT_LEGS_RIGHT_MESH_TYPE = GL_LINE_LOOP;
 const int VERTEX_DOG_FRONT_LEGS_RIGHT_NUM_VERTICES = sizeof(VERTEX_DOG_FRONT_LEGS_RIGHT) / (sizeof(float) * 2);

 const float VERTEX_DOG_FRONT_LEGS_LEFT[22] =
{
    0.04f, -0.4f,
   -0.04f, -0.4f,
    0.0f, -0.36f,
    0.0f, -0.24f,
   -0.12f, -0.14f,
   -0.12f, -0.04f,
   -0.1f, -0.0f,
    0.0f, -0.02f,
    0.04f, -0.14f,
    0.08f, -0.18f,
    0.08f, -0.24f

};

 const GLenum VERTEX_DOG_FRONT_LEGS_LEFT_MESH_TYPE = GL_LINE_LOOP;
 const int VERTEX_DOG_FRONT_LEGS_LEFT_NUM_VERTICES = sizeof(VERTEX_DOG_FRONT_LEGS_LEFT) / (sizeof(float) * 2);

 const float VERTEX_DOG_BACK_LEGS_RIGHT[22] =
{
    0.2f, -0.4f,
    0.12f, -0.4f,
    0.12f, -0.36f,
    0.16f, -0.32f,
    0.16f, -0.28f,
    0.08f, -0.24f,
    0.08f, -0.2f,
    0.2f, -0.2f,
    0.2f, -0.23f,
    0.24f, -0.26f,
    0.24f, -0.34f,

};

 const GLenum VERTEX_DOG_BACK_LEGS_RIGHT_MESH_TYPE = GL_LINE_LOOP;
 const int VERTEX_DOG_BACK_LEGS_RIGHT_NUM_VERTICES = sizeof(VERTEX_DOG_BACK_LEGS_RIGHT) / (sizeof(float) * 2);

 const float VERTEX_DOG_BACK_LEGS_LEFT[18] =
{
    0.58f, -0.4f,
    0.5f, -0.4f,
    0.4f, -0.27f,
    0.26f, -0.2f,
    0.2f, -0.14f,
    0.2f, -0.04f,
    0.3f, -0.0f,
    0.4f, -0.1f,
    0.46f, -0.2f,
};

 const GLenum VERTEX_DOG_BACK_LEGS_LEFT_MESH_TYPE = GL_LINE_LOOP;
 const int VERTEX_DOG_BACK_LEGS_LEFT_NUM_VERTICES = sizeof(VERTEX_DOG_BACK_LEGS_LEFT) / (sizeof(float) * 2);

 const float VERTEX_DOG_TAIL[10] =
{
    0.4f,  -0.1f,
    0.28f,  0.06f,
    0.3f,  0.24f,
    0.4f,   0.06f,
    0.3f, -0.0f,
};

 const GLenum VERTEX_DOG_TAIL_MESH_TYPE = GL_LINE_LOOP;
 const int VERTEX_DOG_TAIL_NUM_VERTICES = sizeof(VERTEX_DOG_TAIL) / (sizeof(float) * 2);

 const float VERTEX_DOG_BODY[30] =
{
    0.3f,  -0.0f,
    0.2f,   -0.0f,
    0.0f,    0.12f,
    0.0f,    0.28f,
   -0.08f,   0.4f,
   -0.08f,   0.32f,
   -0.11f,  0.32f,
   -0.2f,    0.4f,
   -0.2f,    0.3f,
   -0.26f,   0.34f,
   -0.32f,   0.34f,
   -0.36f,   0.32f,
   -0.36f,   0.22f,
   -0.29f,  0.1f,
   -0.2f,    0.1f,
};

 const GLenum VERTEX_DOG_BODY_MESH_TYPE = GL_LINE_STRIP;
 const int VERTEX_DOG_BODY_NUM_VERTICES = sizeof(VERTEX_DOG_BODY) / (sizeof(float) * 2);
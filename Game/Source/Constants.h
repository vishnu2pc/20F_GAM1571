#pragma once


 enum class EVENT_TYPE {
    INPUT_EVENT,
    SPAWN_PLAYER,
    SPAWN_ENEMY,
    DELETE_ENEMY,
 	NEXT_LEVEL,
 	WIN
};

 enum class LEVEL_TYPE {
 	
     FIRST ,
     SECOND ,
     THIRD
     
 };


    

    extern const float Arena_radius;

    extern  int MIN_VERTICES;
    extern  int MAX_VERTICES;

    
    extern float Spawn_Timer[];
    extern float Player_Radius[];
    extern float Player_Speed[];
    extern float Duration[];
    extern float Arena_Radius[];
    extern float Enemy_Size[];
    extern float Enemy_Speed[];
    

    //extern fw::vec4 Player_Color[];
    //extern fw::vec4 Enemy_Color[];
    //extern fw::vec4 Arena_Color[];
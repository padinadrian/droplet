
#include <gb/gb.h>
#include "Position.h"


typedef enum {
    OBJECT_TYPE_NULL = 0,
    OBJECT_TYPE_DROPLET = 1,

    // Do not put anything past here!
    NUM_OBJECT_TYPES,
} ObjectType;

typedef struct {
    ObjectType object_id;
    Position pos;
    UINT8 state;
} Object;




// static Level level99 {

// };

// Callback type definition
typedef void (*ObjectCallback)(Object*);


void null_object_callback(Object* object_ptr) {
    // Do nothing
}

void droplet_object_callback(Object* object_ptr) {
    // TODO
}

static ObjectCallback callback_lookup[NUM_OBJECT_TYPES] = {
    // 0: Null
    null_object_callback,
    // 1: Droplet
    droplet_object_callback,
};


const UINT8 MAX_OBJECTS = 255;


int run_game() {
    Object object_list[MAX_OBJECTS];
    UINT8 num_objects = 5;


    for (UINT8 i = 0; i <  num_objects; ++i) {
        switch (object_list[i].object_id) {
            case OBJECT_TYPE_DROPLET: {

                break;
            }
            default: {}
        }
    }
}

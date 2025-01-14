#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include <math.h>
#include "globals.h"
#include "utils.h"
#include "Maps/map.h"
#include "Maps/overworld_map.h"
#include "Actor/actor.h"
#include "Actor/player.h"
#include "Actor/npc.h"

static uint32_t animcounter = 0;
const bool DEBUG = false;

void controller_handle(void);

void update(void)
{
    animcounter++;
    for (size_t i = 0; i < npcs_count; i++) {
        npc_update(npcs[i], animcounter);
    }
    controller_handle();
}

uint32_t controllerData1 = 0x00000000;
uint32_t controllerData2 = 0x00000000;

void controller_handle(void) {
    /* Do we need to switch video displays? */
    controller_scan();
    struct controller_data keys = get_keys_pressed();

    controllerData1 = keys.c[0].data;
    controllerData2 = keys.c[1].data;

    // Copying to another struct because I can't find the type
    // TODO: Don't fucking do that
    controller_state_t controller_1_state;
    controller_1_state.A = keys.c[0].A;
    controller_1_state.B = keys.c[0].B;
    controller_1_state.Z = keys.c[0].Z;
    controller_1_state.L = keys.c[0].L;
    controller_1_state.R = keys.c[0].R;
    controller_1_state.up = keys.c[0].up;
    controller_1_state.down = keys.c[0].down;
    controller_1_state.left = keys.c[0].left;
    controller_1_state.right = keys.c[0].right;
    controller_1_state.C_up = keys.c[0].C_up;
    controller_1_state.C_down = keys.c[0].C_down;
    controller_1_state.C_left = keys.c[0].C_left;
    controller_1_state.C_right = keys.c[0].C_right;
    controller_1_state.start = keys.c[0].start;
    controller_1_state.x = keys.c[0].x;
    controller_1_state.y = keys.c[0].y;
    controller_1_state.data = keys.c[0].data;

    if (!menu_open) {
        player_handle_controller(&player, &controller_1_state);
    }
}

void load_textures(void) {
    /* Read in single sprite */
    int fp = dfs_open("/player.sprite");
    player_sprite = malloc( dfs_size( fp ) );
    dfs_read( player_sprite, 1, dfs_size( fp ), fp );
    dfs_close( fp );

    fp = dfs_open("/npc_ghost.sprite");
    npc_ghost = malloc( dfs_size( fp ) );
    dfs_read( npc_ghost, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    
    fp = dfs_open("/tileset_0.sprite");
    map_tile_texture_0 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_0, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_1.sprite");
    map_tile_texture_1 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_1, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_2.sprite");
    map_tile_texture_2 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_2, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_3.sprite");
    map_tile_texture_3 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_3, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_4.sprite");
    map_tile_texture_4 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_4, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_5.sprite");
    map_tile_texture_5 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_5, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_6.sprite");
    map_tile_texture_6 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_6, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_7.sprite");
    map_tile_texture_7 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_7, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_8.sprite");
    map_tile_texture_8 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_8, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_9.sprite");
    map_tile_texture_9 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_9, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_10.sprite");
    map_tile_texture_10 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_10, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_11.sprite");
    map_tile_texture_11 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_11, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_12.sprite");
    map_tile_texture_12 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_12, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_13.sprite");
    map_tile_texture_13 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_13, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_14.sprite");
    map_tile_texture_14 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_14, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_15.sprite");
    map_tile_texture_15 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_15, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    fp = dfs_open("/tileset_16.sprite");
    map_tile_texture_16 = malloc( dfs_size( fp ) );
    dfs_read( map_tile_texture_16, 1, dfs_size( fp ), fp );
    dfs_close( fp );
}

int main( void )
{
    /* Initialize peripherals */
    display_init( RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE );
    dfs_init( DFS_DEFAULT_LOCATION );
    rdp_init();
    controller_init();
    timer_init();
    load_textures();

    uint32_t last_time = get_ticks();

    map = &overworld_map;

    npcs_count = overworld_map.npcs_count;
    for(int i = 0; i < 32; i++) {
        if (i < overworld_map.npcs_count) {
            npcs[i] = overworld_map.npcs[i];

            sprite_t* sprite = npc_ghost;
            int ranAction = random_int(0, 8);
            npc_action_t action = ranAction % 4 == 0 ? Spin : ranAction % 4 == 1 ? Idle : ranAction % 4 == 2 ? Pace : Path;
            int ranDir = random_int(0, 8);
            direction_t direction = ranDir % 4 == 0 ? Up : ranDir % 4 == 1 ? Down : ranDir % 4 == 2 ? Left : Right;
            
            npc_init(npcs[i], sprite, (Vector2){ 32 * i + (35*32), 32 * (i % 2) + (39*32) }, direction, action, 10, 3);
        } else {
            npcs[i] = NULL; // Clear all NPCs in buffer
        }
    }

    player_init(&player, player_sprite, (Vector2){ (overworld_map.width * 32) / 2, (overworld_map.height * 32) / 2 });

    /* Kick off animation update timer to fire thirty times a second */
    // new_timer(TIMER_TICKS(1000000 / 30), TF_CONTINUOUS, update);

    /* Main loop test */
    while(1) 
    {
        disp = 0;

        /* Grab a render buffer */
        while( !(disp = display_lock()) );
       
        /*Fill the screen */
        graphics_fill_screen( disp, 0xFFFFFFFF );

        /* Set the text output color */
        graphics_set_color( 0x0, 0xFFFFFFFF );

        if (screen_size.x == 0 || screen_size.y == 0) {
            screen_size.x = disp->width;
            screen_size.y = disp->height;
        }

        /* Assure RDP is ready for new commands */
        rdp_sync( SYNC_PIPE );

        /* Remove any clipping windows */
        rdp_set_default_clipping();

        /* Enable sprite display instead of solid color fill */
        rdp_enable_texture_copy();

        /* Attach RDP to display */
        rdp_attach( disp );
        
        uint32_t now = get_ticks();
        uint32_t time_delta = now - last_time;
        
        if (time_delta >= TIMER_TICKS(1000000 / 30)) {
            last_time = now;

            update();
        }

        map_draw(&overworld_map, map_tile_texture, 0); // Background
        map_draw(&overworld_map, map_tile_texture, 1); // Layer 0 Foregrounds
        map_draw(&overworld_map, map_tile_texture, 2); // Layer 1 Foregrounds

        for (size_t i = 0; i < npcs_count; i++) {
            npc_draw(npcs[i], animcounter);
        }

        player_draw(&player, animcounter);

        map_draw(&overworld_map, map_tile_texture, 3); // Layer 2 Foreground

        // // PRINT FPS
        // int fps = TIMER_TICKS(1000000) / time_delta;
        // int lenFPS = snprintf(NULL, 0, "FPS: %d", fps);
        // char *resultFPS = malloc(lenFPS + 1);
        // snprintf(resultFPS, lenFPS + 1, "FPS: %d", fps);
        // graphics_draw_text( disp, 32, 32, resultFPS );
        // free(resultFPS);

        /* Inform the RDP we are finished drawing and that any pending operations should be flushed */
        rdp_detach();

        /* 
            End Hardware Rendering 
        */

        /* Force backbuffer flip */
        display_show(disp);
    }
}

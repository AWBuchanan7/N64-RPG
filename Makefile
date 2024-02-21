all: n64rpg.z64
.PHONY: all

BUILD_DIR = build
include $(N64_INST)/include/n64.mk

SRC = src/main.c src/globals.c src/utils.c src/Actor/actor.c src/Actor/player.c src/Actor/npc.c src/Maps/map.c
OBJS = $(SRC:%.c=$(BUILD_DIR)/%.o)
DEPS = $(SRC:%.c=$(BUILD_DIR)/%.d)

SPRITE_DIR=filesystem
PNG_DIR=assets
SPRITE_MANIFEST_TXT := $(PNG_DIR)/manifest.txt
MKSPRITE := mksprite
REDIRECT_STDOUT := >/dev/null

n64rpg.z64: N64_ROM_TITLE = "n64rpg"
n64rpg.z64: $(BUILD_DIR)/n64rpg.dfs

$(BUILD_DIR)/n64rpg.dfs: $(wildcard filesystem/*)
$(BUILD_DIR)/n64rpg.elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) $(SPRITE_DIR) *.z64
.PHONY: clean

assets:
	mkdir ./filesystem
	mksprite --verbose --output filesystem/ assets/venusaur.png
	mksprite --verbose --output filesystem/ assets/aang.png
	mksprite --verbose --output filesystem/ assets/player.png
	mksprite --verbose --output filesystem/ assets/npc_ghost.png
	mksprite --verbose --output filesystem/ assets/peach.png
	mksprite --verbose --output filesystem/ assets/yugi.png
	mksprite --verbose --output filesystem/ assets/rick.png
	mksprite --verbose --output filesystem/ assets/cursor.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_0.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_1.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_2.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_3.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_4.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_5.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_6.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_7.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_8.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_9.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_10.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_11.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_12.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_13.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_14.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_15.png
	mksprite --verbose --output filesystem/ tileset_generated_parts/tileset_16.png
.PHONY: assets

-include $(DEPS)

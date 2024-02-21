# RPG Engine for the Nintendo 64

This is my personal fork of [breadbored](https://github.com/breadbored)'s project [N64-RPG](https://github.com/breadbored/N64-RPG). It has been restructured for a simple, native Linux development environment and to my personal preferences. This fork is intended exclusively as a learning experience for me and I offer no real support for it.

## About

This unnamed project is an attempt to write all the parts of an RPG from scratch. Below is the list of features currently being written:

- [x] Actors
- [x] Player
- [x] Camera
- [x] NPCs
- [x] Collision
- [ ] Map Rendering
  - [x] Background (Landscape) Tilemap
  - [x] Foreground (Structure / Building) Tilemap
  - [ ] NPC Map Layer
  - [ ] Entrance/Exit Layer
    - [ ] Entrance/Exit Triggers
    - [ ] Map Switching
  - [x] Map Builder (external tool; Tiled)
  - [x] Tilemap Renderer from Map Builder's Binaries

## Setup

This project assumes you are running Linux and have installed [libdragon](https://github.com/DragonMinded/libdragon).

It has been exclusively tested on `Debian 12.5` and `Ubuntu 23.10`, with `Libdragon 13.2.0`. Builds have been tested on an NTSC Nintendo 64 with an `Everdrive X7` running `OS 3.07`.

To build the N64 rom file `n64rpg.z64` run:

- `make assets`
- `make`

## Editing the Map with Tiled

The map was generated using [Tiled](https://thorbjorn.itch.io/tiled?download). You can find the project file at `map/n64-rpg.tiled-project`. I export as a CSV called `overworld.csv` and it will generate a CSV for each layer.

To build the map, run the included tool with `python3 tools/makemap.py` to generate the map file.

### Important notes

I work only in the positive area (0,0) and higher. Do not add any tiles in the negative coordinates or it will shift the entire map.

Tiled does not export with perfect coordinates in CSV format, so every layer must have a tile in the (0,0) coordinate. This is to prevent offset problems. For example, the background layer has a grass tile at (0,0), and the foreground layer has a tree.

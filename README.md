# my_world 🌍

A 3D isometric map renderer built in C using CSFML.

## Overview

This project implements an isometric projection engine that transforms
a 3D height map into a 2D wireframe rendered in a graphical window.

## Features

- Isometric projection of 3D points to 2D screen coordinates
- Wireframe rendering of the full map using CSFML vertex arrays
- Configurable sampling rate (zoom level)
- Centered display with translation offset

## Dependencies

- CSFML
- epiclang

## Build

```bash
make
```

## Usage

```bash
./my_world
```

## Control
- ZQSD Move the map in x, y axis
- R Reset the seed
- A Zoomed out
- E Zoomed
- 1 Height increased mode
- 2 Height decrease mode
- 3 Decreased the radius
- 4 Increased the radius

## Author

Ethan Legendre — Epitech RENNES | Baptiste Le Gourrierec - Epitech RENNES

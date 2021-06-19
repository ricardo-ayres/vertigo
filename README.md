# Vertigo

[Vertigo](http://stjerneskud.info/vertigo/ "Vertigo") is a public domain
flight simulator, written by Anton Norup Sørensen.

Emphasis is on realism of the flight-model, with several types of air- and
space-crafts selectable.


## This repo and modifications from version 0.26

This repository is pretty much a mirror from version 0.26 with minor fixes to
allow compilation in modern Linux with Allegro 4.4 and static CGUI 2.1.0.
I have also added a few more screen resolutions and increased the drawing
distance from 10km to 100km.


### Instructions

- Install or download & compile allegro 4.4
- Point `ALLEGRO` in `makedefs` to the directory of the allegro installation
(typically `/usr/include`)
- Download and compile CGUI with `./fix.sh unix && STATICLINK=1 make lib`
it's not necessary to install it.
- Point `CGUIPATH` in `makedefs` to the directory you just built CGUI
- Compile vertigo with `make` and run with `./Xvertigo`
- Select your desired screen resolution and restart the game to see it take
effect.
- Have fun :)

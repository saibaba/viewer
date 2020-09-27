Introduction
============


This example shows the bare minimum required to create a class using convenience macros: class init, inst init, inst structure.

Wanted to see what the macros expand to? Use this command:

```
% gcc -E  viewer-file.c `pkg-config --cflags glib-2.0 gobject-2.0`
```

Two ways to comile and run
===

Without any tool
----------------

```
# compile:
% gcc viewer-file.c main.c `pkg-config --cflags --libs glib-2.0 gobject-2.0`  -o viewer-file
% run: you know
```

With Meson
------

```
# compile and run:
% rm -rf build && meson build && cd build && meson test
```


Ref
====
* https://developer.gnome.org/gobject/stable/gtype-conventions.html
* https://en.wikibooks.org/wiki/C_Programming/GObject
* https://code.woboq.org/gtk/include/glib-2.0/gobject/gtype.h.html to find precise declrations/definitions created by various macros
* https://github.com/jonnenauha/code/blob/master/gobject-tutorial/gobject-tutorial.txt
* https://titanwolf.org/Network/Articles/Article?AID=6b744c76-440b-4b32-826e-e428c8be2e5c#gsc.tab=0

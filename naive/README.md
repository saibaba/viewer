Introduction
============


This example shows creating your own oo system using GType mechanism from GObject system. Nothing else from GObject is used.

This is basically demoing for OO using just GType and create fundamental type than using GObject".


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
===
https://mail.gnome.org/archives/gtk-list/2004-August/msg00198.html

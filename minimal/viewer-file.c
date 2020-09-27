#include "viewer-file.h"

/*
 * Since we defined the class as final (non-derivable) via G_DELCARE_FINAL_TYPE, there is no point in making the instance structure 
 * to others (deriving classes) via header file, So, define in the C file here.
 * Also, final types do not need private a structure to store instance private data - all can be in this structure only as it is not available
 * for subclassing anyway.
 * Note that the instance of a final class is not embedded in the instance structures of any derived classes, because, the class is final after all.
 */
struct _ViewerFile {
  GObject parent_instance;

};


/*******

The G_DEFINE_TYPE creates viewer_file_get_type function automatically (with static variable to hold GType, so not thread safe). It will be like this:

GType viewer_file_get_type (void)
{
  static GType type = 0;
  if (type == 0) {
    const GTypeInfo info = {
      // You fill this structure.
    };
    type = g_type_register_static (G_TYPE_OBJECT,
                                   "ViewerFile",
                                   &info, 0);
  }
  return type;
}

If you want above to be multi threaded or customizing, you manually create it instead of depending on G_DEFINE_TYPE to create one and mutex lock around 'type == 0'
But the example given below is a bit different (notice user of g_once_init_enter):
https://developer.gnome.org/gobject/stable/gobject-Type-Information.html#G-DEFINE-TYPE-EXTENDED:CAPS


Note that G_DEFINE_TYPE also defines a parent class pointer accessible from the whole .c file
Additionally it adds private instance data to the type if using G_DEFINE_TYPE_WITH_PRIVATE.

*******/


G_DEFINE_TYPE(ViewerFile, viewer_file, G_TYPE_OBJECT)

ViewerFile *viewer_file_new(void)
{
  // just to show that viewer_file_parent_class is made available by G_DEFINE_TYPE
  gpointer p = viewer_file_parent_class;

  // just to show that ViewerFileClass structure is also auto created
  ViewerFileClass *cp = NULL;


  return VIEWER_FILE (g_object_new(VIEWER_TYPE_FILE, 0));
}

static void viewer_file_class_init(ViewerFileClass *klass)
{
  g_print("viewer_file_class_init called\n");
}

static void viewer_file_init(ViewerFile *self)
{
  g_print("viewer_file_init called\n");
}

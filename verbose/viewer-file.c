#include "viewer-file.h"

/*
 * Since we defined the class as final (non-derivable) via G_DELCARE_FINAL_TYPE, there is no point in making the instance structure 
 * to others (deriving classes) via header file, So, define in the C file here.
 * Also, final types do not need private a structure to store instance private data - all can be in this structure only as it is not available
 * for subclassing anyway.
 * Note that the instance of a final class is not embedded in the instance structures of any derived classes, because, the class is final after all.
 */


struct _ViewerFileClass 
{
  GObjectClass parent_class;
};


struct _ViewerFile
{
  GObject parent_instance;
};

static void viewer_file_class_init(gpointer klass, gpointer class_data)
{
  g_return_if_fail(VIEWER_IS_FILE_CLASS(klass));
  g_print("class init called\n");
}

static void viewer_file_init(GTypeInstance *instance, gpointer klass)
{
  g_return_if_fail(VIEWER_IS_FILE(instance));
  g_return_if_fail(VIEWER_IS_FILE_CLASS(klass));
  g_return_if_fail(VIEWER_FILE_GET_CLASS(instance) == klass);
  g_print("instance init called\n");
}

GType viewer_file_get_type (void)
{
  static volatile GType type = 0;
  if (g_once_init_enter(&type))
  {
    const GTypeInfo info = {
      sizeof(ViewerFileClass),
      NULL, /* base_init   : see this for purpose: https://api.gtkd.org/gobject.c.types.GClassInitFunc.html */
      NULL, /* base_finalize */
      viewer_file_class_init,
      NULL, /* class finalizer */
      NULL, /* class data */
      sizeof(ViewerFile),
      0,     /* n_preallocs */
      viewer_file_init
    };

    GType ltype = g_type_register_static(G_TYPE_OBJECT, "ViewerFile", &info, 0);
 
    /* GType ltype = g_type_register_static_simple (G_TYPE_OBJECT,
                                                 "ViewerFile",
                                                 sizeof(ViewerFileClass),
                                                 viewer_file_class_init,
                                                 sizeof(ViewerFile),
                                                 viewer_file_init,
                                                 0); */
    g_once_init_leave(&type, ltype);
  }
  return type;
}

ViewerFile *viewer_file_new(void)
{
  return VIEWER_FILE (g_object_new(VIEWER_TYPE_FILE, 0));
}


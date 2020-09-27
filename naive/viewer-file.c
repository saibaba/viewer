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
  GTypeClass gtypeclass;
};


struct _ViewerFile
{
  GTypeInstance gtype;
};

static void viewer_file_class_init(gpointer klass, gpointer class_data)
{
  g_print("class init called\n");
}

static void viewer_file_init(GTypeInstance *instance, gpointer klass)
{
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

    static const GTypeFundamentalInfo fundamental_info = 
    {
      G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE
    };
 
    GType ltype = g_type_register_fundamental(g_type_fundamental_next(), "ViewerFile", &info, &fundamental_info, 0);
 
    g_once_init_leave(&type, ltype);
  }
  return type;
}

ViewerFile *viewer_file_new(void)
{
  return (ViewerFile *) (g_type_create_instance(viewer_file_get_type()));
}


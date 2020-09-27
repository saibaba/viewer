#ifndef __VIEWER_FILE_H__
#define __VIEWER_FILE_H__

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _ViewerFile ViewerFile;
typedef struct _ViewerFileClass ViewerFileClass;

GType viewer_file_get_type (void);

/*
 * method defn.
 */
ViewerFile *viewer_file_new(void);

G_END_DECLS

#endif /* __VIEWER_FILE_H__ */

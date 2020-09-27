#include "viewer-file.h"

#include <glib.h>
#include <locale.h>

typedef struct {
  ViewerFile *obj;
} ViewerFileFixture;


static void
viewer_file_fixture_set_up (ViewerFileFixture *fixture,
                          gconstpointer user_data)
{
  fixture->obj = viewer_file_new ();
}

static void
viewer_file_fixture_tear_down (ViewerFileFixture *fixture,
                               gconstpointer user_data)
{
  g_clear_object (&fixture->obj);
}

static void test_new(ViewerFileFixture *fixture,
                      gconstpointer user_data)
{
  ViewerFile *vf = viewer_file_new();
  g_assert_nonnull(vf);

  g_object_unref(vf);
}

int main(int argc, char **argv) {

  setlocale (LC_ALL, "");

  g_test_init (&argc, &argv, NULL);

  g_test_add("/viewer-file/test_new", ViewerFileFixture, "some-user-data",  viewer_file_fixture_set_up, test_new, viewer_file_fixture_tear_down);
  return g_test_run();
}

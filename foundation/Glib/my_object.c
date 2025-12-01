#include <glib-object.h>
#include <stdio.h>

// --- Type and Structure Definitions ---

typedef struct _MyObject MyObject;
typedef struct _MyObjectClass MyObjectClass;

struct _MyObject {
    GObject parent_instance;
    gint count;
};

struct _MyObjectClass {
    GObjectClass parent_class;
    void (*say_hello) (MyObject *self, const gchar *message);
};

// --- GObject Boilerplate Macros ---

#define MY_TYPE_OBJECT (my_object_get_type ())
#define MY_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_TYPE_OBJECT, MyObject))
#define MY_IS_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MY_TYPE_OBJECT))
#define MY_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MY_TYPE_OBJECT, MyObjectClass))

GType my_object_get_type (void);

// ---  Class and Instance Initialization ---

static void my_object_say_hello (MyObject *self, const gchar *message);

static void my_object_class_init (MyObjectClass *klass) {
    klass->say_hello = my_object_say_hello;
}

static void my_object_init (MyObject *self) {
    self->count = 0;
    g_print("MyObject instance initialized.\n");
}

GType my_object_get_type (void) {
    static GType type = 0;

    if (type == 0) {
        const GTypeInfo info = {
            sizeof (MyObjectClass), 
            NULL,             
            NULL,         
            (GClassInitFunc) my_object_class_init, 
            NULL,       
            NULL,         
            sizeof (MyObject), 
            0,           
            (GInstanceInitFunc) my_object_init,
            NULL  
        };

        type = g_type_register_static (G_TYPE_OBJECT,
                                       "MyObject",
                                       &info,
                                       0);
    }

    return type;
}

// ---  Method Implementation ---

static void my_object_say_hello (MyObject *self, const gchar *message) {
    self->count++;
    g_print("Hello from MyObject! Message: \"%s\" (Call count: %d)\n",
            message, self->count);
}

// --- Main Application ---

int main (int argc, char *argv[]) {
    g_type_init();

    MyObject *obj = g_object_new(MY_TYPE_OBJECT, NULL);
    g_print("Created object of type: %s\n", g_type_name(G_OBJECT_TYPE(obj)));

    MyObjectClass *klass = MY_OBJECT_CLASS(G_OBJECT_GET_CLASS(obj));

    klass->say_hello(obj, "This is the first call.");
    klass->say_hello(obj, "GObject is powerful.");

    g_object_unref(obj);
    g_print("Object destroyed.\n");

    return 0;
}
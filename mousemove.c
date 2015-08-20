#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <gtk/gtk.h>

Display *dpy;
Window root_window;

void showDisplay();
void moveMouse();

int main(int argc, char *argv[]) {
	showDisplay(argc, argv);
	return 0;
}

void showDisplay(int argc, char *argv[]) {
	gtk_init (&argc, &argv);
	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget* button = gtk_button_new();
	gtk_button_set_label((GtkButton*) button, "Click me");
	g_signal_connect(button, "clicked", G_CALLBACK (moveMouse), button);
	gtk_container_add(GTK_CONTAINER (window), button);
	gtk_widget_show  (button);
	gtk_widget_show  (window);
	gtk_main ();
}

void moveMouse() {
	dpy = XOpenDisplay(0);
	root_window = XRootWindow(dpy, 0);
	XSelectInput(dpy, root_window, KeyReleaseMask);
	XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, 100, 100);
	XFlush(dpy); // Flushes the output buffer, therefore updates the cursor's position
}

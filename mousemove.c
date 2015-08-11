#include <stdio.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <gtk/gtk.h>

Display *dpy;
Window root_window;

void showDisplay();
void moveMouse();

int main() {
	showDisplay();
	moveMouse();
	return 1;
}

void showDisplay() {
	//GtkWidget* label = gtk_label_new ("A");
	//gtk_widget_show_all(label);
}

void moveMouse() {
	dpy = XOpenDisplay(0);
	root_window = XRootWindow(dpy, 0);
	XSelectInput(dpy, root_window, KeyReleaseMask);
	XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, 100, 100);
	XFlush(dpy); // Flushes the output buffer, therefore updates the cursor's position
}

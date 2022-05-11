#include <allegro.h>
#include <stdlib.h>




void initAlleg()
{
    allegro_init();
    install_mouse();
    install_keyboard();

    set_color_depth(desktop_color_depth());//largeur/hauteur
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,800,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);

}

#include "mlx.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    void *mlx;
    void *win;

    // Inizializza la connessione con il server X
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Crea una finestra di 800x600
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "So_Long Window");
    if (!win)
        return (1);

    // Rende la finestra visibile
    mlx_loop(mlx);
    return (0);
}
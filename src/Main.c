#include "/home/codeleaded/System/Static/Library/Image.h"

int main() {
    int width = 256, height = 256;
    int *buffer = (int *)malloc(width * height * sizeof(int));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer[y * width + x] = 0xFFFF0000;
        }
    }

    if (save_png("output.png", buffer, width, height) == 0) {
        printf("PNG gespeichert: output.png\n");
    } else {
        printf("Fehler beim Speichern von PNG\n");
    }
    free(buffer);


    int new_width, new_height;
    int *loaded_buffer = load_png("output.png", &new_width, &new_height);
    if (loaded_buffer) {
        printf("PNG geladen: %dx%d Pixel\n", new_width, new_height);
        free(loaded_buffer);
    } else {
        printf("Fehler beim Laden von PNG\n");
    }

    return 0;
}
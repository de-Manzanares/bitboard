#include <string>

int coordinateIndex(const std::string& coordinate)
{
    int index;

    if ((coordinate[0] < 'a' || coordinate[0] > 'h') ||
            (coordinate[1] < '1' || coordinate[1] > '8')) {
        index = 333;
    }
    else {
        int file = 'h' - coordinate[0];
        int rank = 8 * (coordinate[1] - '1');

        index = rank + file;
    }

    return index;
}

#include <string>

int coordinateIndex(const std::string& coordinate)
{
    int index;

    if (coordinate.length() !=2 ||
        coordinate[0] < 'a' || coordinate[0] > 'h' ||
        coordinate[1] < '1' || coordinate[1] > '8') {
        return 333;
    }

    int file = 'h' - coordinate[0];
    int rank = 8 * (coordinate[1] - '1');

    index = rank + file;

    return index;
}

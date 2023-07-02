#include <string>

int coordinateIndex(const std::string& coordinate)
{
    int file = 'h' - coordinate[0];
    int rank = 8 * (coordinate[1] - '1');

    return (rank + file);
}

#include "../h/error.hpp"

void logSDLError( std::ostream &os, const std::string &msg )
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

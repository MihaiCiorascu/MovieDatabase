#include "FileWatchList.h"
#include <fstream>

void FileWatchList::openInApp() const
{
    this->writeToFile();
    std::string commandToOpenFile = "start " + this->fileName;
    system(commandToOpenFile.c_str());
}

Movie FileWatchList::getMovieByPosition(int position) const
{
    return this->movies[position];
}
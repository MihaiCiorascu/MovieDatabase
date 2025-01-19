//
// Created by Mihai on 6/1/2024.
//

#ifndef OOP_A10_MIHAICIORASCU_COMMAND_H
#define OOP_A10_MIHAICIORASCU_COMMAND_H

#include "Repository.h"

class Command {
public:
    virtual ~Command() {}
    virtual void executeUndo() = 0;
    virtual void executeRedo() = 0;
};

class AddCommand : public Command {
private:
    Repository& repository;
    Movie movie;
public:
    AddCommand(Repository& repository, const Movie& movie) : repository{repository}, movie{movie} {}
    void executeUndo() override {
        this->repository.removeMovie(this->movie);
    }
    void executeRedo() override {
        this->repository.addMovie(this->movie);
    }
};

class RemoveCommand : public Command {
private:
    Repository& repository;
    Movie movie;
public:
    RemoveCommand(Repository& repository, const Movie& movie) : repository{repository}, movie{movie} {}
    void executeUndo() override {
        this->repository.addMovie(this->movie);
    }
    void executeRedo() override {
        this->repository.removeMovie(this->movie);
    }
};

class UpdateCommand : public Command {
private:
    Repository& repository;
    Movie oldMovie, newMovie;
    int position;
public:
    UpdateCommand(Repository& repository, const Movie& oldMovie, const Movie& newMovie, const int position) : repository{repository}, oldMovie{oldMovie}, newMovie{newMovie}, position{position} {}
    void executeUndo() override {
        this->repository.updateMovie(this->position, this->oldMovie);
    }
    void executeRedo() override {
        this->repository.updateMovie(this->position, this->newMovie);
    }
};



#endif //OOP_A10_MIHAICIORASCU_COMMAND_H

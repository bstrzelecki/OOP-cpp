#include <fstream>
#include <conio.h>
#include "World.h"

#include "IControllable.h"
#include "Human.h"

class Entity;

void World::RunOneFrame() {
    RunOneFrame(0);
}

World::World(int x, int y) {
    sizeY = y;
    sizeX = x;
    batch = new RenderBatch(x,y);
}

World::~World() {
    delete batch;
    dispose();
}

void World::dispose() {
    for (Entity* e: entities) {
        delete e;
    }
    entities.clear();
}

void World::AddEntity(Entity* e) {
    if(!isDeleted(e)){
        added.push_back(e);
        e->SetWorld(this);
    }
}

int World::GetSizeX() const {
    return sizeX;
}

int World::GetSizeY() const {
    return sizeY;
}

bool World::IsTileEmpty(int x, int y) {
    for (Entity* e:entities) {
        if(e->GetPosition() == Position(x, y)){
            return false;
        }
    }
    return true;
}

void World::NotifyUpdate(Entity* sender) {
    Position sPos = sender->GetPosition();
    for (Entity* e: entities) {
        if(isDeleted(e))continue;
        if(e->GetPosition() == sPos && e != sender){
            e->OnCollision(sender, &journal);
        }
    }
}

bool World::isDeleted(const Entity* e) {
    for (Entity* removed: markedForRemoval){
        if(e==removed){
            return true;
        }
    }
    return false;
}

void World::DeleteEntity(Entity* entity) {
    if(!isDeleted(entity))
        markedForRemoval.push_back(entity);
}

Entity* World::GetEntityAtPosition(int x, int y) {
    for (Entity* e:entities) {
        if(e->GetPosition() == Position(x, y)){
            return e;
        }
    }
    return nullptr;
}



void World::RunOneFrame(char input) {
    applyAddition();
    applyRemoval();
    journal.Clear();
    for (Entity* e: entities) {
        if(isDeleted(e))continue;
        if(IControllable* c = dynamic_cast<IControllable*>(e)){
            c->Update(&journal, input);
        }else{
            e->Update(&journal);
        }
    }
    entities.sort([](Entity* a, Entity* b){return a->GetInitiative() > b->GetInitiative();});
    Draw();
    journal.Print(std::cout);
    std::cout<<std::flush;
}

void World::applyAddition() {
    for (Entity* e: added){
        if(IsTileEmpty(e->GetPosition().x, e->GetPosition().y)){
            entities.push_back(e);
        }else{
            DeleteEntity(e);
        }
    }
    added.clear();
}

void World::Serialize(const std::string& fileName) {
    Serializer s;
    s.SetSubEntryName("World");
    s.SetInt("sizeX", sizeX);
    s.SetInt("sizeY", sizeY);
    for(Entity* e: entities){
        s.SetSubEntryName(e->ToString());
        e->Serialize(s);
    }
    s.Save(fileName);
}

void World::Load(const std::string& fileName) {
    dispose();
    std::ifstream stream;
    stream.open(fileName);
    if(!stream.good()){
        std::cout<<"File does not exists";
        stream.close();
        return;
    }
    std::string line;
    Entity* current = nullptr;
    SerializationContext context;
    bool isInitializing = false;
    while(true){
        stream>>line;
        if(line=="!!"){
            if(current!= nullptr){
                if(isInitializing){
                    reInit(context);
                }else{
                    current->Deserialize(context);
                }
            }
            break;
        }
        if(line.starts_with('!')){
            if(isInitializing){
                reInit(context);
                isInitializing = false;
            }else if(current!= nullptr){
                current->Deserialize(context);

            }
            context.Clear();
            std::string trimmed = line.substr( 0, line.size() - 1 );
            trimmed = trimmed.substr( 1, trimmed.size() );
            if(trimmed == "World"){
                current = nullptr;
                isInitializing = true;
            }else{
                current = Entity::GetEntityFromString("class " + trimmed);
                AddEntity(current);
            }
        }else{
            context.Populate(line);
        }
    }
    applyAddition();
}

void World::Run() {
    applyAddition();
    Draw();
    int c;
    while(true){
        c=getch();
        switch(c){
            case ARROW_INPUT:
                system("cls");
                c=getch();
                RunOneFrame(c);
                break;
            case PASS:
            case ABILITY:
                system("cls");
                RunOneFrame(c);
                break;
            case SAVE:
                Serialize(getFileName());
                Draw();
                break;
            case LOAD:
                Load(getFileName());
                Draw();
                break;
            case RESIZE:
                system("cls");
                int newX, newY;
                std::cout<<"Map width:";
                std::cin>>newX;
                std::cout<<"Map height:";
                std::cin>>newY;
                delete batch;
                batch = new RenderBatch(newX, newY);
                for(Entity* e: entities){
                    if(e->GetPosition().x >= newX){
                        DeleteEntity(e);
                    }
                    if(e->GetPosition().y >= newY){
                        DeleteEntity(e);
                    }
                }
                sizeX = newX;
                sizeY = newY;
                applyRemoval();
                system("cls");
                Draw();
                break;
            case EXIT:
                return;
        }
    }
}

void World::Draw() {
    batch->Clear();
    for (Entity* e: entities) {
        if(isDeleted(e))continue;
        e->Draw(batch);
    }
    applyRemoval();
    std::cout<<"Bartosz Strzelecki 184529\n";
    batch->Render(std::cout);
}

void World::applyRemoval() {
    for (Entity* removed: markedForRemoval){
        entities.remove(removed);
        added.remove(removed);
        delete removed;
    }
    markedForRemoval.clear();
}

std::string World::getFileName() {
    std::string file;
    system("cls");
    std::cout<<"File name:";
    std::cin>>file;
    return file;
}

void World::reInit(SerializationContext context) {
    delete batch;
    sizeY = context.GetInt("sizeY");
    sizeX = context.GetInt("sizeX");
    batch = new RenderBatch(sizeX,sizeY);
}


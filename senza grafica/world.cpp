
class World {
  public:
    int mat[HEIGHT][WIDTH];

    World();
    void show();
};

World::World()
{
  for (int y=0; y<HEIGHT; y++)
    for (int x=0; x<WIDTH; x++)
      this->mat[y][x] = 0;
}

void World::show()
{
  for (int y=0; y<HEIGHT; y++){
    for (int x=0; x<WIDTH; x++)
      cout << static_cast<char>(this->mat[y][x]);
    cout << endl;
  }
}

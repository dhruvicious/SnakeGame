#include "Board.h"

// Vector2Equal: Functor for comparing two Vector2 objects for equality in unordered_map.
// Compares the integer values of x and y to avoid floating-point precision issues.
bool Vector2Equal::operator()(const Vector2 &FirstVector, const Vector2 &SecondVector) const noexcept
{
    return static_cast<int>(FirstVector.x) == static_cast<int>(SecondVector.x) &&
           static_cast<int>(FirstVector.y) == static_cast<int>(SecondVector.y);
}

// Vector2Hash: Functor for hashing a Vector2 object for use in unordered_map.
// Hashes the integer values of x and y, combining them to produce a unique hash.
size_t Vector2Hash::operator()(const Vector2 &Vector) const noexcept
{
    const int x = static_cast<int>(Vector.x);
    const int y = static_cast<int>(Vector.y);
    return std::hash<int>()(x) ^ (std::hash<int>()(y) << 1);
}

// Constructor: Initializes the board with the given level data
Board::Board(std::vector<std::vector<bool>> LevelData) : LevelData_(std::move(LevelData))
{
    LevelYSize_ = LevelData_.size();         // Set board height
    LevelXSize_ = LevelData_.front().size(); // Set board width
    BoardMap_.clear();                       // Clear any existing board data
    TransformLevelData();                    // Convert level data to board map
}

// Converts the 2D level data into the BoardMap_ structure
void Board::TransformLevelData()
{
    if (!LevelData_.empty())
    {
        for (size_t y = 0; y < LevelYSize_; y++)
        {
            for (size_t x = 0; x < LevelXSize_; x++)
            {
                if (LevelData_.at(y).at(x) == 0)
                {
                    BoardMap_.emplace(Vector2{(float)x, (float)y}, ECellType::EMPTY);
                }
                else
                {
                    BoardMap_.emplace(Vector2{(float)x, (float)y}, ECellType::WALL);
                }
            }
        }
    }
}

// Returns the cell type at the given position, or OUT_OF_BORDER if not found
ECellType Board::GetCellInfo(Vector2 Position) const
{
    if (BoardMap_.find(Position) != BoardMap_.end())
    {
        return BoardMap_.at(Position);
    }
    return ECellType::OUT_OF_BORDER;
}

// Sets the cell type at the given position if it exists
void Board::SetCellType(Vector2 Position, ECellType CellType)
{
    if (BoardMap_.find(Position) != BoardMap_.end())
    {
        BoardMap_.at(Position) = CellType;
    }
}

// Returns the entire board map (positions and their cell types)
std::unordered_map<Vector2, ECellType, Vector2Hash, Vector2Equal> Board::getLevelData() const
{
    return BoardMap_;
}

// Finds and returns the first empty cell position, or {1,1} if none found
Vector2 Board::GetEmptyCell() const
{
    for (auto i : BoardMap_)
    {
        if (i.second == ECellType::EMPTY)
        {
            return i.first;
        }
    }
    return {1, 1};
}

// Returns the width of the board
size_t Board::GetLevelXSize() const
{
    return LevelXSize_;
}

// Returns the height of the board
size_t Board::GetLevelYSize() const
{
    return LevelYSize_;
}

// Destructor
Board::~Board() = default;

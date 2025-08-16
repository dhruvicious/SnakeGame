#pragma once
#include "IObject.h"
#include <raylib.h>
#include <raymath.h>
#include <vector>

/**
 * @brief Represents the possible movement directions for the snake.
 */
enum class EDirection
{
  UP,    /**< Move upwards. */
  RIGHT, /**< Move rightwards. */
  LEFT,  /**< Move leftwards. */
  DOWN   /**< Move downwards. */
};

/**
 * @brief Represents the snake entity and its behavior in the game.
 *
 * Inherits from IMove to provide movement logic.
 */
class Snake : public IObject
{
public:
  /**
   * @brief Constructs a Snake object at the given starting position.
   * @param StartingPos The initial position of the snake's head.
   * @param Board Reference to the game board.
   */
  Snake(Vector2 StartingPos, std::shared_ptr<Board> Board);

  /**
   * @brief Gets the positions of all tail segments.
   * @return A vector containing the positions of the tail segments.
   */
  std::vector<Vector2> GetTailPosition() const;

  /**
   * @brief Gets the current position of the snake's head.
   * @return The position of the head.
   */
  inline Vector2 GetHeadPosition() const
  {
    return Position_;
  }
  /**
   * @brief Changes the size of the snake's tail.
   * @param Size The amount to change the tail size by (positive to grow, negative to shrink).
   */
  void ChangeTailSizeBy(int Size);

  /**
   * @brief Moves the snake in the current direction.
   *
   * Overrides IMove::Move.
   */
  void Move() override;

  /**
   * @brief Checks if the snake is alive.
   * @return True if the snake is alive, false otherwise.
   */
  inline bool isAlive() const
  {
    return bIsAlive_;
  }

  /**
   * @brief Sets the direction of the snake's head.
   * @param Direction The new direction to set.
   */
  void SetDirection(EDirection Direction);

  /**
   * @brief Gets the current direction of the snake's head.
   * @return The current direction.
   */
  inline EDirection GetDirection() const noexcept
  {
    return Direction_;
  }

  inline EDirection GetHeadDirection() const noexcept
  {
    return HeadDirection_;
  }
  /**
   * @brief Destroys the Snake object.
   */
  virtual ~Snake() = default;

protected:
  void SetHeadPosition(const Vector2 Position) noexcept;

private:
  std::vector<Vector2> TailPosition_; ///< Positions of the tail segments.
  EDirection Direction_;
  bool bIsAlive_;            ///< Indicates if the snake is alive.
  EDirection HeadDirection_; /**< Indicates the direction for Snake movement. */
};
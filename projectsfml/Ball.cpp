#include "Ball.h"
#include "Paddle.h"

const float BALL_VELOCITY_X = 20;


Ball::Ball(int _radius)
{
    SetRadius(_radius);
}

// collision
void Ball::Update(Paddle* pOne, Paddle* pTwo, int _height)
{
    // collision with paddles
    m_position += m_velocity;

    //left paddle: check if it collides with dimensions of the paddleand
    // make sure it will not go through it with velocity without contact
    if(GetPositionY() > pOne->GetPositionY() && GetPositionY() < pOne->GetPositionY() + pOne->GetHeight() &&
        GetPositionX() > pOne->GetPositionX() && GetPositionX() < pOne->GetPositionX() + BALL_VELOCITY_X+1)
        m_velocity.x = m_velocity.x * -1;

    // right paddle: check if it collides with dimensions of the paddle and
    // make sure it will not go through it with velocity without contact
    if(GetPositionY() > pTwo->GetPositionY() && GetPositionY() < pTwo->GetPositionY() + pTwo->GetHeight() &&
        GetPositionX() > pTwo->GetPositionX() - 2 * pTwo->GetWidth() && GetPositionX() < pTwo->GetPositionX() + BALL_VELOCITY_X+1)
        m_velocity.x = m_velocity.x * -1;

    // collision with the walls
    // if y > maximum y down - diameter or y < minimum y up + diameter
    if(GetPositionY() > _height - GetRadius() * 2 || GetPositionY() < GetRadius() * 2)
        m_velocity.y = m_velocity.y * -1;
}


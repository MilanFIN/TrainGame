#include "gameexception.h"

GameException::GameException(const QString &msg):
    msg_(msg)
{

}

QString GameException::msg() const
{
    return msg_;
}

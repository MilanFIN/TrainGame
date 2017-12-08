#ifndef ENDGAME_H
#define ENDGAME_H

#include <QDialog>

namespace Ui {
class endGame;
}

/**
 * @brief The endGame class dialog informs player when player lose
 */
class endGame : public QDialog
{
    Q_OBJECT

public:
    explicit endGame(QWidget *parent = 0);
    ~endGame();

private:
    Ui::endGame *ui;
};

#endif // ENDGAME_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QString>
#include <QStringList>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_B_reset_clicked();

    void on_B_check_clicked();

    void on_B_help_clicked();

private:
    Ui::MainWindow *ui;
    QString currentQuestionString;
    QStringList parts, sentences;
    QMessageBox messageBox;

    int score = 0, currentIndex = 0;
    bool hintUsed = false;

    QString getInititalChars(QString);
    QString getFormattedQString(QString);

    void updateScore();
    void updateQuestion();
    void getSentencesFromFile();
    void clearAnswerFields();
    void resetGame();
    int randInt(int low, int high);
    void clearHintFields();
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getSentencesFromFile();
    currentQuestionString = sentences.at(currentIndex);
    updateQuestion();
}

void MainWindow::resetGame() {
    hintUsed = false;
    score = 0;
    // currentIndex = randInt(0,sentences.size()-1);
    currentIndex = 0;

    ui->B_help->setText("Hint");
    updateScore();
    updateQuestion();
}

void MainWindow::getSentencesFromFile() {
    QFile infile(":/proverbs.txt");
    infile.open(QIODevice::ReadOnly);
    QString data(infile.readAll());
    infile.close();

    sentences = data.split("\n");
}

void MainWindow::clearHintFields() {
    qDebug() << "In clearHint";
    ui->label->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->label_5->setText("");
    ui->label_6->setText("");
    ui->label_7->setText("");
    ui->label_8->setText("");
    ui->label_9->setText("");
}

QString MainWindow::getInititalChars(QString sentence) {
    parts = sentence.split(" ");
    QString initials = "";

    for (int i = 0; i < parts.size(); i++) {
        initials += parts.at(i).at(0).toUpper();
    }

    return initials;
}

QString MainWindow::getFormattedQString(QString s) {
    return s.prepend("<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">").append("</span></p></body></html>");
}

void MainWindow::clearAnswerFields() {
    ui->LE_answer1->setText("");
    ui->LE_answer1->setStyleSheet("");

    ui->LE_answer1_2->setText("");
    ui->LE_answer1_2->setStyleSheet("");

    ui->LE_answer1_3->setText("");
    ui->LE_answer1_3->setStyleSheet("");

    ui->LE_answer1_4->setText("");
    ui->LE_answer1_4->setStyleSheet("");

    ui->LE_answer1_5->setText("");
    ui->LE_answer1_5->setStyleSheet("");

    ui->LE_answer1_6->setText("");
    ui->LE_answer1_6->setStyleSheet("");

    ui->LE_answer1_7->setText("");
    ui->LE_answer1_7->setStyleSheet("");

    ui->LE_answer1_8->setText("");
    ui->LE_answer1_8->setStyleSheet("");

    ui->LE_answer1_9->setText("");
    ui->LE_answer1_9->setStyleSheet("");
}

void MainWindow::updateQuestion() {
    if (currentIndex >= sentences.size()) {
        QMessageBox::warning(this, "Enough!", "Well, you've been playing this game for a long time. Go out for a walk, NOW!");
        resetGame();
    }

    currentQuestionString = sentences.at(currentIndex);
    qDebug() << "currentQuestionString = " << currentQuestionString;
    qDebug() << "currentIndex = " << currentIndex;

    QString s = getInititalChars(currentQuestionString);

    clearAnswerFields();
    clearHintFields();
    hintUsed = false;

    // set the alphabets and show the required text fields
    switch (s.size()) {
    case 9:
        ui->L_label1_9->setVisible(true);
        ui->LE_answer1_9->setVisible(true);
        ui->label_9->setVisible(true);

        ui->L_label1_9->setText(getFormattedQString(s.at(8)));

    case 8:
        ui->L_label1_8->setVisible(true);
        ui->LE_answer1_8->setVisible(true);
        ui->label_8->setVisible(true);
        ui->L_label1_8->setText(getFormattedQString(s.at(7)));

    case 7:
        ui->L_label1_7->setVisible(true);
        ui->LE_answer1_7->setVisible(true);
        ui->label_7->setVisible(true);
        ui->L_label1_7->setText(getFormattedQString(s.at(6)));

    case 6:
        ui->L_label1_6->setVisible(true);
        ui->LE_answer1_6->setVisible(true);
        ui->label_6->setVisible(true);
        ui->L_label1_6->setText(getFormattedQString(s.at(5)));

    case 5:
        ui->L_label1_5->setVisible(true);
        ui->LE_answer1_5->setVisible(true);
        ui->label_5->setVisible(true);
        ui->L_label1_5->setText(getFormattedQString(s.at(4)));

    case 4:
        ui->L_label1_4->setVisible(true);
        ui->LE_answer1_4->setVisible(true);
        ui->label_4->setVisible(true);
        ui->L_label1_4->setText(getFormattedQString(s.at(3)));

    case 3:
        ui->L_label1_3->setVisible(true);
        ui->LE_answer1_3->setVisible(true);
        ui->label_3->setVisible(true);
        ui->L_label1_3->setText(getFormattedQString(s.at(2)));

    case 2:
        ui->L_label1_2->setVisible(true);
        ui->LE_answer1_2->setVisible(true);
        ui->label_2->setVisible(true);
        ui->L_label1_2->setText(getFormattedQString(s.at(1)));

    case 1:
        ui->L_label1->setVisible(true);
        ui->LE_answer1->setVisible(true);
        ui->label->setVisible(true);
        ui->L_label1->setText(getFormattedQString(s.at(0)));
    }

    // hide the labels and textfields which aren't required
    switch (9 - s.size()) {
    case 9:
        ui->L_label1->setVisible(false);
        ui->LE_answer1->setVisible(false);
        ui->label->setVisible(false);

    case 8:
        ui->L_label1_2->setVisible(false);
        ui->LE_answer1_2->setVisible(false);
        ui->label_2->setVisible(false);

    case 7:
        ui->L_label1_3->setVisible(false);
        ui->LE_answer1_3->setVisible(false);
        ui->label_3->setVisible(false);

    case 6:
        ui->L_label1_4->setVisible(false);
        ui->LE_answer1_4->setVisible(false);
        ui->label_4->setVisible(false);

    case 5:
        ui->L_label1_5->setVisible(false);
        ui->LE_answer1_5->setVisible(false);
        ui->label_5->setVisible(false);

    case 4:
        ui->L_label1_6->setVisible(false);
        ui->LE_answer1_6->setVisible(false);
        ui->label_6->setVisible(false);

    case 3:
        ui->L_label1_7->setVisible(false);
        ui->LE_answer1_7->setVisible(false);
        ui->label_7->setVisible(false);

    case 2:
        ui->L_label1_8->setVisible(false);
        ui->LE_answer1_8->setVisible(false);
        ui->label_8->setVisible(false);

    case 1:
        ui->L_label1_9->setVisible(false);
        ui->LE_answer1_9->setVisible(false);
        ui->label_9->setVisible(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_reset_clicked()
{
    resetGame();
}

void MainWindow::on_B_check_clicked()
{
    bool allCorrect = true;

    switch (parts.size()) {
    case 9:
        if (ui->LE_answer1_9->text().toUpper() != parts.at(8).toUpper()) {
            ui->LE_answer1_9->setStyleSheet("color: rgb(255, 101, 0);");
            allCorrect = false;
        }
        else {
            ui->LE_answer1_9->setStyleSheet("");
        }

    case 8:
        if (ui->LE_answer1_8->text().toUpper() != parts.at(7).toUpper()) {
            ui->LE_answer1_8->setStyleSheet("color: rgb(255, 101, 0);");

            allCorrect = false;
        }
        else {
            ui->LE_answer1_8->setStyleSheet("");
        }

    case 7:
        if (ui->LE_answer1_7->text().toUpper() != parts.at(6).toUpper()) {
            ui->LE_answer1_7->setStyleSheet("color: rgb(255, 101, 0);");

            allCorrect = false;
        }
        else {
            ui->LE_answer1_7->setStyleSheet("");
        }

    case 6:
        if (ui->LE_answer1_6->text().toUpper() != parts.at(5).toUpper()) {
            ui->LE_answer1_6->setStyleSheet("color: rgb(255, 101, 0);");

            allCorrect = false;
        }
        else {
            ui->LE_answer1_6->setStyleSheet("");
        }

    case 5:
        if (ui->LE_answer1_5->text().toUpper() != parts.at(4).toUpper()) {
            ui->LE_answer1_5->setStyleSheet("color: rgb(255, 101, 0);");
            allCorrect = false;
        }
        else {
            ui->LE_answer1_5->setStyleSheet("");
        }

    case 4:
        if (ui->LE_answer1_4->text().toUpper() != parts.at(3).toUpper()) {
            ui->LE_answer1_4->setStyleSheet("color: rgb(255, 101, 0);");
            allCorrect = false;
        }
        else {
            ui->LE_answer1_4->setStyleSheet("");
        }

    case 3:
        if (ui->LE_answer1_3->text().toUpper() != parts.at(2).toUpper()) {
            ui->LE_answer1_3->setStyleSheet("color: rgb(255, 101, 0);");
            allCorrect = false;
        }
        else {
            ui->LE_answer1_3->setStyleSheet("");
        }

    case 2:
        if (ui->LE_answer1_2->text().toUpper() != parts.at(1).toUpper()) {
            ui->LE_answer1_2->setStyleSheet("color: rgb(255, 101, 0);");
            allCorrect = false;
        }
        else {
            ui->LE_answer1_2->setStyleSheet("");
        }

    case 1:
        if (ui->LE_answer1->text().toUpper() != parts.at(0).toUpper()) {
            ui->LE_answer1->setStyleSheet("color: rgb(255, 101, 0);");
            allCorrect = false;
        }
        else {
            ui->LE_answer1->setStyleSheet("");
        }
    }

    if (!allCorrect) {
        QMessageBox::critical(this, "Try again", "Something's not right!\nPlease try again.");
    }
    else {
        if (hintUsed)
            score += 5;
        else
            score += 10;

        updateScore();

        currentIndex++;
        updateQuestion();
    }
}

void MainWindow::on_B_help_clicked()
{
    qDebug() << "hintUsed = " << hintUsed;
    if (hintUsed) {
        currentIndex++;
        updateQuestion();
        ui->B_help->setText("Hint");
    }
    else {
        hintUsed = true;
        ui->B_help->setText("Give Up");

        switch(parts.size()) {
        case 9:
            ui->label_9->setText(QString::number(parts.at(8).size()));

        case 8:
            ui->label_8->setText(QString::number(parts.at(7).size()));

        case 7:
            ui->label_7->setText(QString::number(parts.at(6).size()));

        case 6:
            ui->label_6->setText(QString::number(parts.at(5).size()));

        case 5:
            ui->label_5->setText(QString::number(parts.at(4).size()));

        case 4:
            ui->label_4->setText(QString::number(parts.at(3).size()));

        case 3:
            ui->label_3->setText(QString::number(parts.at(2).size()));

        case 2:
            ui->label_2->setText(QString::number(parts.at(1).size()));

        case 1:
            ui->label->setText(QString::number(parts.at(0).size()));
        }
    }
}
 void MainWindow::updateScore() {
     QString text = "Score: " + QString::number(score);
     text = text.prepend("<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; font-style:italic;\">");
     text = text.append(" </span></p></body></html>"); // that space is IMPORTANT
     ui->L_score->setText(text);
 }

 int MainWindow::randInt(int low, int high)
 {
 // Random number between low and high
 return qrand() % ((high + 1) - low) + low;
 }

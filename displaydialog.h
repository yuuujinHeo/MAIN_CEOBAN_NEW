#ifndef DISPLAYDIALOG_H
#define DISPLAYDIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class DisplayDialog;
}

typedef struct _WAITING_{
    QLabel *pin;
    QLabel *menu;
    QLabel *status;
}WAITING;

typedef struct _OUTLET_{
    QLabel *pin;
    QLabel *menu;
    QLabel *status;
    int status_flag;
}OUTLET;

class DisplayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayDialog(QWidget *parent = nullptr);
    ~DisplayDialog();

    void Enalble_AD();
    void Disable_AD();
    void Set_Mode(int _mode);
    void Set_ForcedMode(int _mode);
    QString notice;
    int notice_count;
private:
    void settingUI();
    WAITING waiting[7];
    OUTLET outlet[2][3];


    int display_mode;
    int forced_display_mode;
    int use_ad;
    int count_ad;

private slots:
    void updateDisplay();
private:
    Ui::DisplayDialog *ui;
    QTimer *timer;
};

#endif // DISPLAYDIALOG_H

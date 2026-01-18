#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

// --- ĐIỀU KIỆN 2 & 5: Cấu trúc dữ liệu và Mảng ---
struct Vehicle {
    QString licensePlate; // Kiểu string
    int type;            // Kiểu int (0: Xe máy, 1: Ô tô)
    bool isInParking;    // Kiểu bool
    double entryTime;    // Kiểu double
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // --- ĐIỀU KIỆN 4: 05 hàm tự định nghĩa ---
    void addVehicle(QString plate, int type);
    double calculateFee(int type, double hours);
    void displayParkingLot();
    void saveToFile();
    // (Hàm thứ 5 và 6 là các slot xử lý nút bấm bên dưới)

private slots:
    // Các hàm xử lý sự kiện nút bấm (Slots)
    void on_btnIn_clicked();
    void on_btnOut_clicked();

private:
    Ui::MainWindow *ui;

    // --- ĐIỀU KIỆN 5: Mảng một chiều (1D Array) ---
    Vehicle parkingLot[100];
    int currentVehicleCount = 0;  // Biến đếm số xe hiện tại
};

#endif // MAINWINDOW_H

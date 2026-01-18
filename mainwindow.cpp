#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox> // Thư viện để hiện hộp thoại thông báo

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Cấu hình bảng hiển thị ngay khi mở ứng dụng
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"STT", "Biển số", "Loại xe"});
    // Cho phép các cột tự dãn đều
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- HÀM 1: Thêm xe vào mảng (Đáp ứng mục 5: Mảng 1D) ---
void MainWindow::addVehicle(QString plate, int type) {
    if (currentVehicleCount < 100) {
        parkingLot[currentVehicleCount].licensePlate = plate;
        parkingLot[currentVehicleCount].type = type;
        parkingLot[currentVehicleCount].isInParking = true;
        parkingLot[currentVehicleCount].entryTime = 8.0; // Giả định vào lúc 8h sáng
        currentVehicleCount++;
    } else {
        QMessageBox::critical(this, "Lỗi", "Bãi xe đã đầy chỗ!");
    }
}

// --- HÀM 2: Tính tiền (Đáp ứng mục 6: Phép toán và mục 3: Switch-case) ---
double MainWindow::calculateFee(int type, double hours) {
    double pricePerHour = 0;
    switch(type) {
    case 0: pricePerHour = 5000; break;  // Xe máy
    case 1: pricePerHour = 20000; break; // Ô tô
    }
    return pricePerHour * hours; // Phép nhân tính tổng tiền
}

// --- HÀM 3: Hiển thị lên Table (Đáp ứng mục 3: Vòng lặp for) ---
void MainWindow::displayParkingLot() {
    ui->tableWidget->setRowCount(0); // Xóa trắng bảng để nạp lại dữ liệu mới
    for (int i = 0; i < currentVehicleCount; i++) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Cột 0: Số thứ tự
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(i + 1)));
        // Cột 1: Biển số
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(parkingLot[i].licensePlate));
        // Cột 2: Loại xe (Dùng if-else để chuyển số thành chữ)
        QString typeStr = (parkingLot[i].type == 0) ? "Xe Máy" : "Ô tô";
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(typeStr));
    }
}

// --- HÀM 4: Lưu dữ liệu (Đáp ứng mục 8: Đọc/Lưu file) ---
void MainWindow::saveToFile() {
    QFile file("parking_data.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < currentVehicleCount; i++) {
            // Lưu định dạng: BiểnSố|LoạiXe
            out << parkingLot[i].licensePlate << "|" << parkingLot[i].type << "\n";
        }
        file.close();
    }
}

// --- HÀM 5: Xử lý nút "Cho xe vào" ---
void MainWindow::on_btnIn_clicked()
{
    QString plate = ui->inputPlate->text().trimmed(); // Lấy chữ và xóa khoảng trắng thừa
    int type = ui->comboType->currentIndex(); // 0: Xe máy, 1: Ô tô

    if (plate.isEmpty()) {
        QMessageBox::warning(this, "Nhắc nhở", "Vui lòng nhập biển số xe!");
        return;
    }

    addVehicle(plate, type); // Gọi hàm thêm vào mảng
    displayParkingLot();      // Cập nhật bảng
    saveToFile();            // Lưu file
    ui->inputPlate->clear(); // Xóa ô nhập để nhập xe tiếp theo
}

// --- HÀM 6: Xử lý nút "Cho xe ra & Tính tiền" ---
void MainWindow::on_btnOut_clicked()
{
    QString plate = ui->inputPlate->text().trimmed();
    int findIndex = -1;

    // Vòng lặp tìm vị trí xe trong mảng (Mục 3)
    for (int i = 0; i < currentVehicleCount; i++) {
        if (parkingLot[i].licensePlate == plate) {
            findIndex = i;
            break;
        }
    }

    if (findIndex != -1) {
        // Giả sử xe đã gửi 2 tiếng để tính tiền
        double fee = calculateFee(parkingLot[findIndex].type, 2.0);
        QMessageBox::information(this, "Thanh toán",
                                 "Xe: " + plate + "\nSố tiền: " + QString::number(fee) + " VNĐ");

        // Thuật toán xóa phần tử khỏi mảng (Dồn mảng)
        for (int i = findIndex; i < currentVehicleCount - 1; i++) {
            parkingLot[i] = parkingLot[i + 1];
        }
        currentVehicleCount--; // Giảm số lượng xe hiện có

        displayParkingLot(); // Vẽ lại bảng
        saveToFile();       // Cập nhật lại file
    } else {
        QMessageBox::warning(this, "Lỗi", "Biển số này không có trong bãi xe!");
    }
}

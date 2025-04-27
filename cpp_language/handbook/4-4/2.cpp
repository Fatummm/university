#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

// Ваш код будет вставлен здесь:
class NotifierBase {
private:

public:
    virtual void Notify(const std::string& msg) const = 0;
};


class SmsNotifier: public NotifierBase {
private:
    std::string phone_number;
public:
    SmsNotifier(const std::string& s): phone_number(s) {};

    void Notify(const std::string& msg) const override {
        SendSms(phone_number, msg);
    }
};

class EmailNotifier: public NotifierBase {
private:
    std::string email_address;
public:
    EmailNotifier(const std::string& email): email_address(email) {}

    void Notify(const std::string& msg) const override {
        SendEmail(email_address, msg);
    }
};
// Реализуйте в вашем решении классы NotifierBase, SmsNotifier и EmailNotifier,
// чтобы следующий код заработал как ожидается:

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}
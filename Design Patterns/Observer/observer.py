from abc import ABC, abstractmethod

#########################################
# Observer Interface (Abstract Base Class)
#########################################

class NotificationAlert(ABC):
    @abstractmethod
    def update(self):
        pass

#########################################
# Observable Interface (Abstract Base Class)
#########################################

class StockObservable(ABC):
    @abstractmethod
    def add(self, observer: NotificationAlert):
        pass

    @abstractmethod
    def remove(self, observer: NotificationAlert):
        pass

    @abstractmethod
    def notify_subscribers(self):
        pass

    @abstractmethod
    def set_stock_count(self, new_stock: int):
        pass

    @abstractmethod
    def get_stock_count(self) -> int:
        pass

#########################################
# Concrete Observable Implementation
#########################################

class IphoneObservableImpl(StockObservable):
    def __init__(self):
        self._observers = []         # List of subscribers
        self._stock_count = 0        # Initial stock

    def add(self, observer: NotificationAlert):
        self._observers.append(observer)

    def remove(self, observer: NotificationAlert):
        self._observers.remove(observer)

    def notify_subscribers(self):
        for observer in self._observers:
            observer.update()

    def set_stock_count(self, new_stock: int):
        if self._stock_count == 0:
            self.notify_subscribers()  # Notify only when stock was 0
        self._stock_count += new_stock

    def get_stock_count(self) -> int:
        return self._stock_count

#########################################
# Concrete Observer: Email Notification
#########################################

class EmailAlertObserverImpl(NotificationAlert):
    def __init__(self, email_id: str, observable: StockObservable):
        self.email_id = email_id
        self.observable = observable

    def update(self):
        self.send_email(self.email_id, "Product is in stock, hurry up!")

    def send_email(self, email_id: str, message: str):
        print(f"Email sent to: {email_id}")

#########################################
# Concrete Observer: Mobile Notification
#########################################

class MobileAlertObserverImpl(NotificationAlert):
    def __init__(self, username: str, observable: StockObservable):
        self.username = username
        self.observable = observable

    def update(self):
        self.send_sms(self.username, "Product is in stock, hurry up!")

    def send_sms(self, username: str, message: str):
        print(f"SMS sent to: {username}")

#########################################
# Main Execution Logic
#########################################

if __name__ == "__main__":
    # Create observable (iPhone stock tracker)
    iphone_stock = IphoneObservableImpl()

    # Create observers
    ob1 = EmailAlertObserverImpl("xyz@gmail.com", iphone_stock)
    ob2 = EmailAlertObserverImpl("xyz@outlook.com", iphone_stock)
    ob3 = MobileAlertObserverImpl("xyz", iphone_stock)

    # Register observers
    iphone_stock.add(ob1)
    iphone_stock.add(ob2)
    iphone_stock.add(ob3)

    # Update stock (should notify since stock was 0)
    iphone_stock.set_stock_count(10)

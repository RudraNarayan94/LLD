#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////
// Observer Interface Declaration //
/////////////////////////////////////

/*
 * Interface representing a notification alert.
 * All concrete observers must implement the update() method.
 */
class NotificationAlert
{
public:
  virtual void update() = 0;
};

//////////////////////////////////////
// Observable Interface Declaration //
//////////////////////////////////////

/*
 * Interface representing an observable (subject).
 * Defines methods for adding/removing observers,
 * notifying them, and modifying internal state (stock count).
 */
class StockObservable
{
public:
  virtual void add(NotificationAlert *observer) = 0;
  virtual void remove(NotificationAlert *observer) = 0;
  virtual void notifySubscriber() = 0;
  virtual void setStockCount(int newStockAdded) = 0;
  virtual int getStockCount() = 0;
};

//////////////////////////////////////////////
// Concrete Observable Implementation Class //
//////////////////////////////////////////////

/*
 * Concrete implementation of StockObservable for iPhone.
 * Manages stock and notifies observers when stock becomes available.
 */
class IphoneObservableImpl : public StockObservable
{
private:
  list<NotificationAlert *> observerList; // List of observers (subscribers)
  int stockCount = 0;                     // Current stock of the product

public:
  // Add an observer to the list
  void add(NotificationAlert *observer) override
  {
    observerList.push_back(observer);
  }

  // Remove an observer from the list
  void remove(NotificationAlert *observer) override
  {
    observerList.remove(observer);
  }

  // Notify all subscribed observers
  void notifySubscriber() override
  {
    for (auto observer : observerList)
    {
      observer->update();
    }
  }

  // Set stock count and notify subscribers if stock was previously 0
  void setStockCount(int newStockAdded) override
  {
    if (stockCount == 0)
      notifySubscriber(); // Notify only when stock was 0 and is being refilled

    stockCount += newStockAdded;
  }

  // Get current stock count
  int getStockCount() override
  {
    return stockCount;
  }
};

/////////////////////////////////////////////////////////
// Concrete Observer - Email Notification Implementation //
/////////////////////////////////////////////////////////

/*
 * Sends an email alert to the user when notified.
 */
class EmailAlertObserverImpl : public NotificationAlert
{
private:
  string emailId;
  StockObservable *observable;

public:
  EmailAlertObserverImpl(string emailId, StockObservable *observable)
  {
    this->emailId = emailId;
    this->observable = observable;
  }

  // Called when observable notifies observers
  void update() override
  {
    sendMail(emailId, "Product is in stock, hurry up!");
  }

private:
  // Simulate sending an email
  void sendMail(string emailId, string msg)
  {
    cout << "Mail sent to: " << emailId << "\n";
  }
};

/////////////////////////////////////////////////////////////
// Concrete Observer - Mobile Notification Implementation //
/////////////////////////////////////////////////////////////

/*
 * Sends a mobile alert to the user when notified.
 */
class MobileAlertObserverImpl : public NotificationAlert
{
private:
  string userName;
  StockObservable *observable;

public:
  MobileAlertObserverImpl(string userName, StockObservable *observable)
  {
    this->userName = userName;
    this->observable = observable;
  }

  // Called when observable notifies observers
  void update() override
  {
    sendMsgOnMobile(userName, "Product is in stock, hurry up!");
  }

private:
  // Simulate sending a mobile message
  void sendMsgOnMobile(string userName, string msg)
  {
    cout << "Msg sent to: " << userName << "\n";
  }
};

////////////////////
// Main Function  //
////////////////////

int main()
{
  // Create an observable object for iPhone stock
  StockObservable *iphoneStockObservable = new IphoneObservableImpl;

  // Create observers (email & mobile notifications)
  NotificationAlert *ob1 = new EmailAlertObserverImpl("xyz@gmail.com", iphoneStockObservable);
  NotificationAlert *ob2 = new EmailAlertObserverImpl("xyz@outlook.com", iphoneStockObservable);
  NotificationAlert *ob3 = new MobileAlertObserverImpl("xyz", iphoneStockObservable);

  // Register observers to the observable
  iphoneStockObservable->add(ob1);
  iphoneStockObservable->add(ob2);
  iphoneStockObservable->add(ob3);

  // Update stock count, which triggers notification if stock was previously 0
  iphoneStockObservable->setStockCount(10);

  return 0;
}

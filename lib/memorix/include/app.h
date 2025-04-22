#ifndef APP_H
#define APP_H

namespace memorix {

class App
{
public:
    App();

    bool IsRunning() const;
    void Update();

private:
    bool is_running_;
};

}  // namespace memorix
#endif  // !APP_H

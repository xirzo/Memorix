#ifndef MEMORIX_H
#define MEMORIX_H

class Memorix
{
public:
    Memorix();

    bool IsRunning() const;
    void Update();

private:
    bool is_running_;
};

#endif  // !MEMORIX_H

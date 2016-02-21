#ifndef TAGCLOUD_H
#define TAGCLOUD_H

#include <QFrame>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

class TagCloud : public QFrame
{
    Q_OBJECT
public:
    using tagPair = std::pair<QString, int>;

    explicit TagCloud(QWidget *parent = 0);
    void addTag(QString tagName, int number);
    void populate(std::vector<tagPair> &tags);
    void unpopulate();

    int getMinFontSize() const;
    void setMinFontSize(int value);

    int getMaxFontSize() const;
    void setMaxFontSize(int value);

signals:

public slots:

private:
    int minFontSize;
    int maxFontSize;

    float tagFontSize(int count);

    QVBoxLayout * verticalLayout;
    float magicLayoutNumber{24.0};
    int minTagCnt;
    int maxTagCnt;
};

#endif // TAGCLOUD_H

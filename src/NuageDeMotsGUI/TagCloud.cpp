#include "TagCloud.h"
#include <QPushButton>
#include <QLabel>
#include <algorithm>
#include <cmath>

TagCloud::TagCloud(QWidget * parent) : QFrame(parent), minFontSize{this->height()/2}, maxFontSize{this->height()*2}
{
    verticalLayout = new QVBoxLayout();
    verticalLayout->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    this->setLayout(verticalLayout);
    this->setStyleSheet("QPushButton {background-color: gray}");
}

void TagCloud::populate(std::vector<tagPair> &tags)
{
    unpopulate();

    minTagCnt = std::min_element(tags.begin(), tags.end(),
                                 [](tagPair p1, tagPair p2){return p1.second < p2.second;})->second;
    maxTagCnt = std::max_element(tags.begin(), tags.end(),
                                 [](tagPair p1, tagPair p2){return p1.second < p2.second;})->second;
    auto numTags = tags.size();

    int part = ceil(numTags/sqrt(numTags));

    QHBoxLayout * row = NULL;
    std::random_shuffle(tags.begin(), tags.end());
    for(unsigned i = 0; i < tags.size(); ++i) {
        if(i % part == 0) {
            row = new QHBoxLayout();
            row->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
            verticalLayout->addLayout(row);
        }

        auto tagName = tags.at(i).first;
        auto tagCount = tags.at(i).second;
        int fSize = tagFontSize(tagCount);
        QLabel * button = new QLabel(tagName);
        QString style{"* { font-size: %1px }"};
        auto styleform = style.arg(fSize);
        button->setStyleSheet(styleform);
        QPalette sample_palette;
        sample_palette.setColor(QPalette::WindowText, QColor(128*fSize/(double)maxFontSize,64*fSize/(double)maxFontSize,255*fSize/(double)maxFontSize));
        button->setPalette(sample_palette);
        row->addWidget(button);
    }
}

void TagCloud::unpopulate()
{
    QLayoutItem *childLayout;
    while ((childLayout = verticalLayout->takeAt(0)) != 0) {
        QLayoutItem *child;
        auto * layout = childLayout->layout();
        while((child = layout->takeAt(0)) != 0) {
            delete child->widget();
        }
        delete childLayout;
    }
}

int TagCloud::getMinFontSize() const
{
    return minFontSize;
}

void TagCloud::setMinFontSize(int value)
{
    minFontSize = value;
}
int TagCloud::getMaxFontSize() const
{
    return maxFontSize;
}

void TagCloud::setMaxFontSize(int value)
{
    maxFontSize = value;
}

float TagCloud::tagFontSize(int count)
{
    return (minFontSize*(-count + maxTagCnt) + maxFontSize*(count - minTagCnt))/
            static_cast<float>(maxTagCnt - minTagCnt);
}

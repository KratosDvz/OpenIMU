#ifndef DBBLOCK_H
#define DBBLOCK_H

#include<QString>
#include<QNetworkReply>
#include<QNetworkAccessManager>
#include"../../acquisition/CJsonSerializer.h"
#include"../../acquisition/WimuRecord.h"
#include"../../algorithm/AlgorithmOutputInfoSerializer.h"

class DbBlock : public QObject
{
    Q_OBJECT

    public:
        DbBlock();
        ~DbBlock();
        std::vector<QString> getDaysInDB();
        bool addRecordInDB(const QString& json);
        bool addResultsInDB(const QString &json);

    signals:
        void updated();


public slots:
        void reponseRecue(QNetworkReply* reply);
        void resultInsertionResponse(QNetworkReply* reply);
     private:
        QNetworkAccessManager* m_manager;
        QTime* m_addRecordTime;
};

#endif // DBWRITEBLOCK_H

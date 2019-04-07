//
// Created by bart on 7-4-19.
//

#include "../api/Database.h"
#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

namespace {

    class DBTest : public testing::Test {
    protected:
        // Remember that SetUp() is run immediately before a test starts.
        // This is a good place to record the start time.
        std::string pathToDBFolder = "../db";
        void SetUp() override {
            // Remove all files of databases to make sure we start with a clean slate
            removeDataBases(pathToDBFolder);
        }

        // TearDown() is invoked immediately after a test finishes.  Here we
        // check if the test was too slow.
        void TearDown() override {
            // Gets the time when the test finishes
            std::cout << "Tearing down test" << std::endl;
        }

        void removeDataBases(std::string pathToFolder) {
            boost::filesystem::path path_to_remove(pathToFolder);
            for (boost::filesystem::directory_iterator end_dir_it, it(path_to_remove); it != end_dir_it; ++it) {
                std::cout << "File in folder: " << it->path() << std::endl;
                boost::filesystem::remove_all(it->path());
            }
        }

        bool fileExists(std::string pathToFile) {
            return boost::filesystem::exists(pathToFile);
        }

    };


// We derive a fixture named IntegerFunctionTest from the QuickTest
// fixture.  All tests using this fixture will be automatically
// required to be quick.
//    class DBTest : public DBTestTemplate {
//        // We don't need any more logic than already in the QuickTest fixture.
//        // Therefore the body is empty.
//    };






//TEST(Database, getIndex) {
//    int index = 0;
////    Transaction t(index, 1, "", "", 0, 0, 0, "Test transaction" ,"ACC");
//    ASSERT_EQ(index, index);
//}

//    TEST_F(DBTest, ErrorWhenDBDoesNotExist) {
//        // Make sure that not db file exists
//        ASSERT_EQ(true, true);
//    }

    TEST_F(DBTest, OpenDBCreatesFileIfNotExist) {
        std::string dbName = "../db/testing.db";
        Database db;
        db.openDatabase(dbName);
        ASSERT_TRUE(fileExists(dbName));
    }

//    TEST_F(DBTest, NewDBIsEmpty) {
//        std::string dbName = "../db/testing.db";
//        Database db;
//        db.openDatabase(dbName);
//
//        ASSERT_TRUE(db.);
//    }

    TEST_F(DBTest, NotConnectedUntilDBIsOpened) {

        Database db;
        ASSERT_FALSE(db.isConnected());
    }

    TEST_F(DBTest, ConnectedWhenDBIsOpened) {
        Database db;
        std::string dbName = "../db/testing.db";
        db.openDatabase(dbName);
        ASSERT_TRUE(db.isConnected());
    }

    TEST_F(DBTest, DBDoesNotExists) {
        Database db;
        std::string dbName = "../db/testing.db";
        ASSERT_FALSE(db.dbFileExists(dbName));
    }

    TEST_F(DBTest, DBDoesExists) {
        Database db;
        std::string dbName = "../db/testing.db";
        db.openDatabase(dbName);
        ASSERT_TRUE(db.dbFileExists(dbName));
    }






//
//bool dbFileExists(std::string dbFile);
//void openDatabase(std::string dbFile);
//bool isConnected();
//void closeDataBase();
//
//bool insertTransaction(Transaction t);
//bool updateTransaction(Transaction t);
//bool deleteTransaction(Transaction t);
//
//int numberOfTransaction();
//
//int tableSize(std::string tableName);
//
//bool emptyDatabase(std::string dbFileName);
//
//bool tableExists(std::string tableName);
//
//bool emptyTable(std::string tableName);
//
//bool dropTable(std::string tableName);
//
//bool tableIsEmpty(std::string tableName);

}
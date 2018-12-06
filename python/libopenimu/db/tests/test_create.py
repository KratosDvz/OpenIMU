
import unittest
import os

from sqlalchemy import create_engine

from libopenimu.models.Base import Base


class CreateTest(unittest.TestCase):

    # All tests will use this name for the database
    TESTDB_NAME = 'test.db'

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_create_database(self):

        # engine = create_engine('sqlite:///:memory:', echo=True)
        engine = create_engine('sqlite:///' + self.TESTDB_NAME, echo=True)

        # Will create all tables
        Base.metadata.create_all(engine)

        # Verify if file exists
        self.assertTrue(os.path.isfile(self.TESTDB_NAME))

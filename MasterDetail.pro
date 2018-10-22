TEMPLATE = subdirs

SUBDIRS = \
    MasterDetail \
    MasterDetailApp \
    MasterDetailTests

MasterDetailApp.depends = MasterDetail
MasterDetailTests.depends = MasterDetail

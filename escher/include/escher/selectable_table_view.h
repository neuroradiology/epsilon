#ifndef ESCHER_SELECTABLE_TABLE_VIEW_H
#define ESCHER_SELECTABLE_TABLE_VIEW_H

#include <escher/table_view.h>
#include <escher/app.h>
#include <escher/table_view_data_source.h>
#include <escher/responder.h>

/* SelectableTableView is a Table View that handles selection. To implement it,
 * it needs a class which should be both data source and view controller. This
 * takes the selectable table view as instance variable and makes it first
 * responder. The selectable table view bubles up events when they do not
 * concern selection. */

class SelectableTableView : public TableView, public Responder {
public:
  SelectableTableView(Responder * parentResponder, TableViewDataSource * dataSource, KDCoordinate topMargin, 
    KDCoordinate rightMargin, KDCoordinate bottomMargin, KDCoordinate leftMargin);
  int selectedRow();
  int selectedColumn();
  virtual bool handleEvent(Ion::Events::Event event) override;
  virtual void didBecomeFirstResponder() override;
  void deselectTable();
  bool setSelectedCellAtLocation(int i, int j);
private:
  int m_selectedCellX;
  int m_selectedCellY;
};

#endif
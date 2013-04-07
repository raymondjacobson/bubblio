class AddBubbleIdToItem < ActiveRecord::Migration
  def change
    add_column :items, :bubble_id, :integer
  end
end

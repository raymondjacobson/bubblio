class AddBubbleIdToLinks < ActiveRecord::Migration
  def change
    add_column :links, :bubble_id, :integer
  end
end

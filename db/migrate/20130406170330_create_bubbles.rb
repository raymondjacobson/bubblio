class CreateBubbles < ActiveRecord::Migration
  def change
    create_table :bubbles do |t|
      t.string :title

      t.timestamps
    end
  end
end

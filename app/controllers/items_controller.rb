class ItemsController < ApplicationController
  before_filter :bubble_owns_item

  def index
    @link = @bubble.links.first
    @item = @bubble.items.new(params[:item])
    if @item.save
      redirect_to bubble_item_path(@item)
    end
  end

  def new
  	@item = @bubble.items.new
  end

  def show
  	@item = @bubble.items.find(params[:id])
  end

  def create
  	@item = @bubble.items.new(params[:item])
    url_hash = params[:hash].to_s
    if url_hash!="" 
      url = "/" + url_hash
    	if @item.save
        flash[:success] = "Item uploaded!"
        redirect_to url_hash
      else
        render 'new'
      end
    else
      if @item.save
        flash[:success] = "Item uploaded!"
        redirect_to :back
      else
        render 'new'
      end
    end
  end

  def destroy
    @item = @bubble.items.find(params[:id])
    @item.destroy
    redirect_to :back
  end

end
